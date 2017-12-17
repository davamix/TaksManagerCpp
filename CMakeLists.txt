cmake_minimum_required (VERSION 3.5)
project ("Task Manager")

set (CMAKE_CXX_STANDARD 11)

add_executable(task_list task_list.cpp task_manager.cpp task.cpp)