#include <iostream>
#include "task.h"

std::string description;

Task::Task(std::string value){
    description = value;
}
std::string Task::get_description() const{
    return description;
}

bool operator==(const Task& a, const Task& b){
    int value = a.get_description().compare(b.get_description());

    if(value == 0)
        return true;
    
    return false;
}
