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

LIST *listHolder;


//------------------------------------Add To List TEST------------------------------------

void TestAddOne(){
    int i = 10;
    void *p = &i;
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    void *result = Get(0);
    TestList(listHolder, p, result, "Add One Value");
    DestroyList();
}


void TestMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    listHolder = InitList((compare) compare_int32_t);
    Add(&a);
    Add(&b);
    Add(&c);
    Add(&d);
    Add(&e);
    Add(&f);
    Add(&g);
    int *result = Get(2);
    TestList(listHolder, &c, result, "Add Multiple Values");
    DestroyList();
}


void TestWholeList(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    int expected[7] = {10,202,192,282,231,12,45};

    listHolder = InitList((compare) compareIntArrays);
    Add(&a);
    Add(&b);
    Add(&c);
    Add(&d);
    Add(&e);
    Add(&f);
    Add(&g);

    int *result;
    result = ToArray(listHolder);

    TestList(listHolder, expected, result, "Test Whole List As Array");
}

//------------------------------------INDEX OF TEST------------------------------------

void TestIndexOf(){
    int i = randomInt();
    int x = randomInt();
    int y = randomInt();
    int z = randomInt();
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);
    Add(&z);
    int three = 3;
    int *thr = &three;
    int result = IndexOf(&y);
    TestList(listHolder, thr, &result, "IndexOf Included int");
    DestroyList();
}

void TestIndexOfFail(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);
    //[10,23,-24,34]
    int result = IndexOf(&z);
    int expected = -1;
    TestList(listHolder,&expected, &result, "IndexOf Fail int");
    DestroyList();
}

void TestWithRandomInsert(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    listHolder = InitList((compare) compare_int32_t);
    Add(&a);
    Add(&b);
    Add(&c);
    Add(&d);
    Add(&e);
    Add(&f);

    int result = IndexOf(&d);

    InsertNodeBeforeTarget(4,&g);

    result = IndexOf(&d);
    int expected = 5;
    TestList(listHolder, &expected, &result, "Add Multiple Values");
    DestroyList();
}

//------------------------------------INSERT BEFORE TEST------------------------------------

void InsertBeforeTest(){
    int i = randomInt();
    int x = randomInt();
    int y = randomInt();
    int z = randomInt();
    listHolder = InitList(compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);

    InsertNodeBeforeTarget(1,&z);
    int *result = Get(0);
    TestList(listHolder,&z, result, "Inserted Before Element Test");
    DestroyList();
}

//------------------------------------INSERT AFTER TEST------------------------------------

void InsertAfterTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);
    InsertNodeAfterTarget(1,&z);
    int *result = Get(1);
    TestList(listHolder,&z, result, "Insert After Element Test");
    DestroyList();
}

void InsertAfterTestTwo(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);
    InsertNodeAfterTarget(2,&z);
    int *result = Get(2);
    TestList(listHolder,&z, result, "Insert After Element Test Two");
    DestroyList();
}

//------------------------------------REMOVE TEST------------------------------------

void removeTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);

    UnlinkNodeByValue(&x);
    int *result = Get(1);
    TestList(listHolder, &y, result, "Remove Node Test");
    DestroyList();
}

void removeAllTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    listHolder = InitList((compare) compare_int32_t);
    Add(&i);
    Add(&x);
    Add(&y);

    UnlinkNodeByValue(&x);
    UnlinkNodeByValue(&i);
    int *result = Get(0);
    TestList(listHolder, &y, result, "Remove All Nodes Test");
    DestroyList();
}


//------------------------------------SORT TEST------------------------------------

void TestSort(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    int expected[7] = {10,12,45,192,202,231,282};
    listHolder = InitList(compare_int32_t);
    Add(&a);
    Add(&b);
    Add(&c);
    Add(&d);
    Add(&e);
    Add(&f);
    Add(&g);

    SortList();

    int *result;
    result = ToArray(listHolder);

    TestList(listHolder, expected, result, "Sort List Test");
    DestroyList();
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


