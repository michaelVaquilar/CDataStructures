/**
 * @file LinkedListTest.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include <stdio.h>
#include "../Include/LinkedList.h"
#include <string.h>
#include <assert.h>
#include "../Include/Utility.h"
#include <stdlib.h>



//------------------------------------Add To List TEST------------------------------------

void TestAddOne(){
    int i = 10;
    void *p = &i;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    void *result = Get(listHolder,0);
    TestList(listHolder, p, result, "Add One Value");
    DestroyList(listHolder);
}


void TestMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&a);
    Add(listHolder,&b);
    Add(listHolder,&c);
    Add(listHolder,&d);
    Add(listHolder,&e);
    Add(listHolder,&f);
    Add(listHolder,&g);
    int *result = Get(listHolder,2);
    TestList(listHolder, &c, result, "Add Multiple Values");
    DestroyList(listHolder);
}


void TestWholeList(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    int expected[7] = {10,202,192,282,231,12,45};
    int *pExected = &expected;

    LIST *listHolder = InitList((compare) compareIntArrays);
    Add(listHolder,&a);
    Add(listHolder,&b);
    Add(listHolder,&c);
    Add(listHolder,&d);
    Add(listHolder,&e);
    Add(listHolder,&f);
    Add(listHolder,&g);

    int *result = ToArray(listHolder);

    TestList(listHolder, pExected, result, "Test Whole List As Array");
}

//------------------------------------INDEX OF TEST------------------------------------

void TestIndexOf(){
    int i = randomInt();
    int x = randomInt();
    int y = randomInt();
    int z = randomInt();
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);
    Add(listHolder,&z);
    int three = 3;
    int *thr = &three;
    int result = IndexOf(listHolder,&y);
    TestList(listHolder, thr, &result, "IndexOf Included int");
    DestroyList(listHolder);
}

void TestIndexOfFail(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);
    //[10,23,-24,34]
    int result = IndexOf(listHolder,&z);
    int expected = -1;
    TestList(listHolder,&expected, &result, "IndexOf Fail int");
    DestroyList(listHolder);
}

void TestWithRandomInsert(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&a);
    Add(listHolder,&b);
    Add(listHolder,&c);
    Add(listHolder,&d);
    Add(listHolder,&e);
    Add(listHolder,&f);

    int result = IndexOf(listHolder,&d);

    InsertNodeBeforeTarget(listHolder,4,&g);

    result = IndexOf(listHolder,&d);
    int expected = 5;
    TestList(listHolder, &expected, &result, "Add Multiple Values");
    DestroyList(listHolder);
}

//------------------------------------INSERT BEFORE TEST------------------------------------

void InsertBeforeTest(){
    int i = randomInt();
    int x = randomInt();
    int y = randomInt();
    int z = randomInt();
    LIST *listHolder = InitList(compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);

    InsertNodeBeforeTarget(listHolder,1,&z);
    int *result = Get(listHolder,0);
    TestList(listHolder,&z, result, "Inserted Before Element Test");
    DestroyList(listHolder);
}

//------------------------------------INSERT AFTER TEST------------------------------------

void InsertAfterTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);
    InsertNodeAfterTarget(listHolder,1,&z);
    int *result = Get(listHolder,1);
    TestList(listHolder,&z, result, "Insert After Element Test");
    DestroyList(listHolder);
}

void InsertAfterTestTwo(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);
    InsertNodeAfterTarget(listHolder,2,&z);
    int *result = Get(listHolder,2);
    TestList(listHolder,&z, result, "Insert After Element Test Two");
    DestroyList(listHolder);
}

//------------------------------------REMOVE TEST------------------------------------

void removeTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);

    UnlinkNodeByValue(listHolder,&x);
    int *result = Get(listHolder,1);
    TestList(listHolder, &y, result, "Remove Node Test");
    DestroyList(listHolder);
}

void removeAllTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i);
    Add(listHolder,&x);
    Add(listHolder,&y);

    UnlinkNodeByValue(listHolder,&x);
    UnlinkNodeByValue(listHolder,&i);
    int *result = Get(listHolder,0);
    TestList(listHolder, &y, result, "Remove All Nodes Test");
    DestroyList(listHolder);
}


//------------------------------------SORT TEST------------------------------------

void TestSort(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    int expected[7] = {10,12,45,192,202,231,282};
    LIST *listHolder = InitList(compare_int32_t);
    Add(listHolder,&a);
    Add(listHolder,&b);
    Add(listHolder,&c);
    Add(listHolder,&d);
    Add(listHolder,&e);
    Add(listHolder,&f);
    Add(listHolder,&g);

    SortList(listHolder);

    int *result;
    result = ToArray(listHolder);

    TestList(listHolder, expected, result, "Sort List Test");
    DestroyList(listHolder);
}


//_____________________________Main Test Entry Point_________________________________


void RunAllListTest(){
    printf("__________________Running List Test____________________");
    TestAddOne();
    TestMultipleValue();
    TestWholeList();
    TestIndexOf();
    TestIndexOfFail();
    TestWithRandomInsert();
    InsertBeforeTest();
    InsertAfterTest();
    InsertAfterTestTwo();
    removeTest();
    removeAllTest();
    TestSort();
    printf("__________________List Test Finished____________________");
}


