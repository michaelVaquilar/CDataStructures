/**
 * @file Stack.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include "../../Include/Stack.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../Include/LinkedList.h"


bool initialized = false;
LIST *list;

void UpdateCount(){
    ourStack->Count = ourStack->list->count;
}

STACK* InitStack(compare Compare){
    initialized = true;
    ourStack = (STACK *)calloc(1, sizeof(STACK));
    if(ourStack == NULL || !InitList(Compare))
        return NULL;
    ourStack->list = list;
    ourStack->Count = 0;
    return ourStack;
}

bool isEmpty(){
    return ourStack->Count <= 0;
}

void *Pop(){
    if(isEmpty()){ return NULL; }
    return RemoveByIndex(0);
}

bool Push(void *data) {
    return InsertNodeBeforeTarget(0, data);
}

void DestroyStack(){
    DestroyList();
    free(ourStack);
}