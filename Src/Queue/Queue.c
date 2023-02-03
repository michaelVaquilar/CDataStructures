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
extern QUEUE *ourQueue;
LIST *list;

QUEUE* InitQueue(compare Compare){
    initialized = true;
    ourQueue = (QUEUE *)calloc(1, sizeof(QUEUE));
    if(ourQueue == NULL || !InitList(Compare))
        return NULL;
    ourQueue->list = list;
    return ourQueue;
}

void Enqueue(void *item){
    Add(item);
}

void* Dequeue(){
    return RemoveByIndex(0);
}

bool isEmpty(){
    return ourQueue->Count <= 0;
}

void DestroyQueue(){
    DestroyList();
    free(ourQueue);
}