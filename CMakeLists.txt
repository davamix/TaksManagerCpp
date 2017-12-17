cmake_minimum_required (VERSION 3.5)
project ("Task Manager")

set (CMAKE_CXX_STANDARD 11)

file (GLOB SOURCE_FILES src/*.cpp)

add_executable(task_list ${SOURCE_FILES})