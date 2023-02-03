cmake_minimum_required(VERSION 3.24)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_library(DataStructures Src/LinkedList/LinkedList.c Util/Utility.c Test/main.c)
