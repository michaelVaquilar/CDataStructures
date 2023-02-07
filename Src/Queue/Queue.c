/**
 * @file Queue.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include "../../Include/Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool initialized = false; //tells us if the user initialized the list (allocating the memory)
LIST *list;

QUEUE* InitQueue(compare Compare){
    initialized = true;
    QUEUE *ourQueue = (QUEUE *)calloc(1, sizeof(QUEUE));
    if(ourQueue == NULL || !InitList(Compare))
        return NULL;
    ourQueue->list = list;
    ourQueue->Count = 0;
    return ourQueue;
}


void Enqueue(QUEUE *ourQueue,void *item){
    Add(ourQueue->list, item);
    ourQueue->Count = ourQueue->list->count;
}

void* Dequeue(QUEUE *ourQueue){
    if(QueueisEmpty(ourQueue))
        return NULL;
    void *result = RemoveByIndex(ourQueue->list, 0);
    ourQueue->Count = ourQueue->list->count;
    return result;

}

bool QueueisEmpty(QUEUE *ourQueue){
    return ourQueue->Count <= 0;
}

void DestroyQueue(QUEUE *ourQueue){
    DestroyList(ourQueue->list);
    free(ourQueue);
}