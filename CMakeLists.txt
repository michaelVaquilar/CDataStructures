cmake_minimum_required(VERSION 3.24)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES Src/LinkedList/LinkedList.c Util/Utility.c Src/Queue/Queue.c Src/Stack/Stack.c Test/TestRun.c Test/LinkedListTest.c Test/StackTest.c Test/StackTest.c)

add_library(DataStructures ${SOURCE_FILES})

add_executable(DataStructuresTest Test/main.c)

target_link_libraries(DataStructuresTest PRIVATE DataStructures)


