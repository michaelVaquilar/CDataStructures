/**
 * @file Queue.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include "../../Include/Queue.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../Include/LinkedList.h"

bool initialized = false; //tells us if the user initialized the list (allocating the memory)
LIST *list;

QUEUE* InitQueue(compare Compare){
    initialized = true;
    ourQueue = (QUEUE *)calloc(1, sizeof(QUEUE));
    if(ourQueue == NULL || !InitList(Compare))
        return NULL;
    ourQueue->list = list;
    ourQueue->Count = 0;
    return ourQueue;
}


void Enqueue(void *item){
    Add(item);
    ourQueue->Count = ourQueue->list->count;
}

void* Dequeue(){
    if(isEmpty())
        return NULL;
    void *result = RemoveByIndex(0);
    ourQueue->Count = ourQueue->list->count;
    return result;

}

bool isEmpty(){
    return ourQueue->Count <= 0;
}

void DestroyQueue(){
    DestroyList();
    free(ourQueue);
}