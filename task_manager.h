#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <iostream>
#include <vector>

#include "task.h"

class TaskManager{
    private:
    const std::string tasks_file_path = "tasks.txt";
    std::vector<Task> tasks;
    void load_tasks(); // load tasks from file into tasks vector

    public:
    TaskManager();
    void add_task(Task& t);
    void remove_task(Task& t);
    void remove_task_at(int index);
    std::vector<Task>& get_tasks();
    void save();
};

#endif