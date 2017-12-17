#ifndef TASK_H
#define TASK_H

#include <iostream>

class Task{
    private:
    std::string description;
    

    public:
    Task(std::string value);
    std::string get_description() const;
};

bool operator==(const Task &a, const Task &b);

#endif