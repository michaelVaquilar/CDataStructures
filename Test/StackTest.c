/**
 * @file StackTest.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include <stdio.h>
#include "../Include/Stack.h"
#include <string.h>
#include <assert.h>
#include "../Include/Utility.h"

STACK *ourStack;


//------------------------------------Add To List TEST------------------------------------

void StackTestPushAndPop(){
    int i = 10;
    ourStack = InitStack((compare) compare_int32_t);
    Push(&i);
    void *result = Pop();
    TestStack(ourStack, &i, result, "Push and Pop Once Test");
    DestroyList();
}


void StackTestPushPopMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    ourStack = InitStack((compare) compare_int32_t);
    Push(&a);
    Push(&b);
    Push(&c);
    Push(&d);
    Push(&e);
    Push(&f);
    Push(&g);
    Pop();
    Pop();
    Pop();
    void *result =Pop();
    TestStack(ourStack, &d, result, "Push and Pop Multiple Values Test");
    DestroyList();
}

void StackTestPopEmpty(){
    ourStack = InitStack((compare) compare_int32_t);
    void *result =Pop();
    TestStack(ourStack, NULL, result, "Stack Pop Empty Stack Test");
    DestroyList();
}

void StackTestPopAll(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    ourStack = InitStack((compare) compare_int32_t);
    Push(&a);
    Push(&b);
    Push(&c);
    Push(&d);
    Push(&e);
    Push(&f);
    Push(&g);
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    void *result =Pop();
    TestStack(ourStack, NULL, result, "Stack Pop All Values Test");
    DestroyList();
}

//_____________________________Main Test Entry Point_________________________________


void RunAllStackTest(){
    printf("__________________Running Stack Test____________________");
    StackTestPushAndPop();
    StackTestPushPopMultipleValue();
    StackTestPopEmpty();
    StackTestPopAll();
    printf("__________________Stack Test Finished____________________");
}
