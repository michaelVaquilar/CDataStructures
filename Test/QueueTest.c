/**
 * @file QueueTest.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include <stdio.h>
#include "../Include/Queue.h"
#include "../Include/Utility.h"

QUEUE *ourQueue;


//------------------------------------Add To List TEST------------------------------------

void QueueTestPushAndPop(){
    int i = 10;
    ourQueue = InitQueue((compare) compare_int32_t);
    Enqueue(&i);
    void *result = Dequeue();
    TestQueue(ourQueue, &i, result, "Add One Value");
    DestroyList();
}


void QueueTestMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    ourQueue = InitQueue((compare) compare_int32_t);
    Enqueue(&a);
    Enqueue(&b);
    Enqueue(&c);
    Enqueue(&d);
    Enqueue(&e);
    Enqueue(&f);
    Enqueue(&g);
    Dequeue();
    Dequeue();
    Dequeue();
    void *result =Dequeue();
    TestQueue(ourQueue, &d, result, "Add Multiple Values");
    DestroyList();
}

void QueueTestDequeueEmpty(){
    ourQueue = InitQueue((compare) compare_int32_t);
    void *result =Dequeue();
    TestQueue(ourQueue, NULL, result, "Add Multiple Values");
    DestroyList();
}

void QueueTestDequeueAll(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    ourQueue = InitQueue((compare) compare_int32_t);
    Enqueue(&a);
    Enqueue(&b);
    Enqueue(&c);
    Enqueue(&d);
    Enqueue(&e);
    Enqueue(&f);
    Enqueue(&g);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    void *result =Dequeue();
    TestQueue(ourQueue, NULL, result, "Add Multiple Values");
    DestroyList();
}

//_____________________________Main Test Entry Point_________________________________


void RunAllQueueTest(){
    printf("__________________Running Queue Test____________________");
    QueueTestPushAndPop();
    QueueTestMultipleValue();
    QueueTestDequeueEmpty();
    QueueTestDequeueAll();
    printf("__________________Queue Test Finished____________________");
}
