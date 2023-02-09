/**
 * @file Stack.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include "../../Include/Stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

STACK* InitStack(compare Compare){
    STACK *ourStack = (STACK *)calloc(1, sizeof(STACK));
    LIST *list = InitList(Compare);
    if(ourStack == NULL || list == NULL)
        return NULL;
    ourStack->list = list;
    ourStack->Count = 0;
    return ourStack;
}

bool StackisEmpty(STACK *ourStack){
    return ourStack->Count <= 0;
}

void *Pop(STACK *ourStack){
    if(StackisEmpty(ourStack)){ return NULL; }
    ourStack->Count = ourStack->list->count;
    return RemoveByIndex(ourStack->list, 0);
}

bool Push(STACK *ourStack, void *data) {
    ourStack->Count = ourStack->list->count;
    return InsertNodeBeforeTarget(ourStack->list,0, data);
}

void DestroyStack(STACK *ourStack){
    DestroyList(ourStack->list);
    free(ourStack);
}