/**
 * @file TestRun.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */
#include "LinkedListTest.c"
#include "QueueTest.c"
#include "StackTest.c"

/**
 * Runs all our test.
 */
void TestAll() {
    RunAllListTest();
    RunAllQueueTest();
    RunAllStackTest();
}