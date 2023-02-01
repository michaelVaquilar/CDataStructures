/**
 * @file LinkedList.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include <stdbool.h>
#include <string.h>


///function that compares two elements, returning:
/// 1 when the first element is greater than the second,
/// -1 when the first element is less than the second,
/// 0 when both elements are equal.
typedef int (*compare)(const void *,const void *);

///Node structure to hold the value along with the next and previous nodes.
typedef struct Node{
    void **value;
    struct Node *next;
    struct Node *previous;
} NODE;

///List structure to hold our head, tail, count and compareTo function.
typedef struct LList{
    NODE *head;
    NODE *tail;
    int count;
    compare CompareTo;
} LIST;


/// Initializes our linked list so we have a memory location for it.
/// Using calloc so that the memory is already set to 0 instead of empty.
/// \param compare, the compareable function for the list.
/// \return true if the memory was allocated, false otherwise.
bool InitList(compare Compare);

/// Adds a value to the linked list.
/// \param value, value to be added
/// \return none, only used as a break.
void Add(void *value);

/// Gets the value at the specific index.
/// \param index, index to get value at.
/// \return the value at the index.
void *Get(int index);

/// Destroys the list aka get's rid of the memory location
/// by freeing the allocated memory.
/// \param list, list to be destroyed
void DestroyList();

/// Prints list to console line by line
void DumpList();

/// Finds the index of a specific value.
/// \param value, the value to look for.
/// \return int, the index of the value.
int IndexOf(void *value);

/// Inserts a node (aka value) before a specific index.
/// \param index, index to insert new value at.
/// \param newValue, new value to be inserted.
/// \return true if the node was successfully added, false otherwise.
bool InsertNodeBeforeTarget(int index, void *newValue);

/// Inserts the new Node (aka value) after the specified index.
/// \param index, index to insert new value at.
/// \param newValue, the new value to insert.
/// \return true if the node was successfully added, false otherwise.
bool InsertNodeAfterTarget(int index, void *newValue);

/// Removes a specific index.
/// \param index, the index to remove
/// \return the data that was stored at the node that was removed.
void *RemoveByIndex(int index);

/// Removes a node by the specified value.
/// \param value, the data value in the node we want to remove.
/// \return true if the node was removed, false otherwise.
bool UnlinkNodeByValue(void *value);

/// Walks to an index inside a specific node.
/// \param temp, temp the node to walk.
/// \param location, location the location to walk to.
/// \return NODE, the node walked to.
NODE *WalkToNode(NODE *temp,int location);

/// Finds the middle of the list.
/// \param start, start the starting Node
/// \return the middle node
NODE *findMid(NODE *start);

/// Sorts the two nodes given.
/// \param leftCursor, leftCursor the left data value
/// \param rightCursor, rightCursor the right data value
/// \return  new sorted node.
NODE *Sort(NODE *leftCursor, NODE *rightCursor);

/// Uses merge sort to sort the linkedlist in ascending order.
/// \param start, start node
/// \return the new sorted node / list
NODE *MergeSort(NODE *start);

/// Calls MergeSort.
void SortList();



#endif //DATASTRUCTURES_LINKEDLIST_H
