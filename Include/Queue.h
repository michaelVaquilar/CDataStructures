/**
 * @file Queue.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/LinkedList.h"

///Stack structure that holds our Queue which is an implementation of our linkedlist.
typedef struct Queue{
    int Count;
    LIST *list;
}QUEUE;

/// Initializes our queue and allocates memory for the queue and list.
/// \param Compare a compare function for the generic data type.
/// \return true if intialized properly, false otherwise.
bool InitQueue(compare Compare);

/// Add's an item to the end of the queue.
/// \param item void * item to add.
void Enqueue(void *item);

/// Dequeues the item at the front of the list (removes the first item).
/// \return the item removed.
void* Dequeue();

/// Checks if the queue is empty.
/// \return true if empty, false otherwise.
bool isEmpty();

#endif //DATASTRUCTURES_QUEUE_H
