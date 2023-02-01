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
#include "../../Include/LinkedList.h"


bool initialized = false;
extern STACK *ourStack;

void UpdateCount(){
    ourStack->Count = ourStack->list->count;
}

bool InitStack(compare Compare){
    initialized = true;
    ourStack = (STACK *)(1, sizeof(STACK));
    if(ourStack == NULL && !InitList(Compare))
        return false;
    return true;
}

bool isEmpty(){
    return ourStack->Count <= 0;
}

void *Pop(){
    return RemoveByIndex(0);
}

bool Push(void *data) {
    return InsertNodeBeforeTarget(0, data);
}