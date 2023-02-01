/**
 * @file LinkedList.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include "../../Include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool initialized = false; //tells us if the user initialized the list (allocating the memory)
extern LIST *list; //external holder for the list. The user must create this.

bool InitList(compare Compare){
    initialized = true;
    list = calloc(1, sizeof(LIST));
    if(list == NULL){
        return false;
    }
    list->CompareTo = Compare;
    return true;
}

NODE *GetHead(NODE *temp) {
    NODE *curr = temp;
    while (curr->previous != NULL) {
        curr = curr->previous;
    }
    return curr;
}

NODE *GetTail(NODE *temp){
    NODE *curr = temp;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}


void Add(void *value) {
    NODE *pList = malloc(sizeof(NODE));
    if(pList == NULL){
        return;
    }
    pList->value = value;
    pList->next = pList->previous = NULL;

    if(!initialized){
        return;
    }
    else if(list->count <= 0) {
        list->head = list->tail = pList;
    }
    else{
        NODE* curr = list->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = pList;
        curr->next->previous = curr;
        list->tail = curr->next;
    }
    list->count++;
}


void *Get(int index){
    NODE *curr = WalkToNode(list->head, index);
    return curr->value;
}



void DestroyList(){
    if(!initialized){ return; }
    free(list);
}


void DumpList(){
    if(list->count <= 0){ return; }
    NODE *curr  = list->head;
    while(curr != NULL){
        printf("%d\n", *(curr->value));
        if(curr->next == NULL){break;}
        curr = curr->next;
    }
}

int IndexOf(void *value){
    if(list->count <= 0) { return -1;}
    NODE *curr  = list->head;
    int counter = 1;
    while(curr != NULL){
        if(list->CompareTo(curr->value, value) == 0){ return counter; }
        if(curr->next == NULL) { return -1; }
        curr = curr->next;
        counter++;
    }
    return -1;
}


bool InsertNodeBeforeTarget(int index, void *newValue){
    if(list->count <= 0){
        return false;
    }
    else if(index == 1){
        NODE* temp = malloc(sizeof(NODE));
        temp->value = newValue;
        temp->next = list->head;
        temp->next->previous = temp;
        temp->previous = NULL;
        list->head = temp;
        list->tail = WalkToNode(temp, list->count);
    }
    else{
        NODE *curr  = WalkToNode(list->head, index - 1);
        NODE* temp = malloc(sizeof(NODE));
        temp->value = newValue;
        temp->next = curr;
        temp->previous = curr->previous;
        temp->next->previous = temp;
        temp->previous->next = temp;

        list->head = GetHead(temp);
        list->tail = GetTail(temp);
    }
    list->count++;
    return true;
}


bool InsertNodeAfterTarget(int index, void *newValue){
    if(list->count <= 0){
        return false;
    }
    return InsertNodeBeforeTarget(index + 1, newValue);;
}



bool UnlinkNodeByValue(void *value){
    if(list->CompareTo(list->head->value, value) == 0){
        list->head = list->head->next;
        list->head->previous = NULL;
        list->tail = GetTail(list->head);
        return true;
    }
    else if(list->CompareTo(list->tail->value, value) == 0){
        list->tail = list->tail->previous;
        list->tail->next = NULL;
        list->head = GetHead(list->tail);
        return true;
    }else{
        int indexOfTarget = IndexOf(value);

        NODE *curr  = WalkToNode(list->head, indexOfTarget - 1);

        curr->next->previous = curr->previous;
        curr->previous->next = curr->next;
        curr = curr->next;
        list->head = GetHead(curr);
        list->tail = GetTail(curr);
        return true;
    }

}

void *RemoveByIndex(int index){
    void *value = Get(index);
    UnlinkNodeByValue(value);
    return value;
}

NODE *WalkToNode(NODE *temp,int location){
    NODE *curr  = temp;
    for(int i = 0; i < location; i++){
        curr = curr->next;
    }
    return curr;
}

NODE *findMid(NODE *start){
    NODE *fastTemp = start->next;
    NODE *slowTemp = start;

    while(fastTemp != NULL){
        fastTemp = fastTemp->next;

        if(fastTemp != NULL) {
            fastTemp = fastTemp->next;
            slowTemp = slowTemp->next;
        }
    }
    return slowTemp;
}

NODE *Sort(NODE *leftCursor, NODE *rightCursor){
    NODE *temp;

    if(leftCursor == NULL)
        return rightCursor;
    if(rightCursor == NULL)
        return leftCursor;
    int x;
    int *pAlloc = &x;
    *pAlloc = list->CompareTo(leftCursor->value, rightCursor->value);
    if(*pAlloc < 0){
        temp = leftCursor;
        temp->next = Sort(leftCursor->next, rightCursor);
        list->tail = temp->next;
    }
    else{
        temp = rightCursor;
        temp->next = Sort(leftCursor, rightCursor->next);
        list->tail = temp->next;
    }
    return temp;
}

NODE *MergeSort(NODE *start){
    if(start == NULL || start->next == NULL)
        return start;

    NODE *endOf1st = findMid(start);
    NODE *begOf2nd = endOf1st->next;
    endOf1st->next = NULL;

    NODE *LHS = start;
    NODE *RHS = begOf2nd;

    LHS = MergeSort(LHS);
    RHS = MergeSort(RHS);

    NODE *sorted = Sort(LHS, RHS);

    list->head = sorted;

    return sorted;

}

void SortList(){
    MergeSort(list->head);
}




