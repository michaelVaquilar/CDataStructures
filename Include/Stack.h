/**
 * @file Stack.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/LinkedList.h"

///Stack structure that holds ourstack which is an implementation of our linkedlist.
typedef struct Stack{
    int Count;
    LIST *list;
}STACK;

#endif //DATASTRUCTURES_STACK_H
