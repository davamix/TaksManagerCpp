#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "include/task.h"
#include "include/task_manager.h"

// Fields
std::vector<Task> tasks;
const int task_description_length = 100;

// Ctor
TaskManager::TaskManager(){
    load_tasks();
}

// Functions
void TaskManager::add_task(Task& t){
    tasks.push_back(t);
}

void TaskManager::remove_task(Task& t){
    tasks.erase(std::remove(tasks.begin(), tasks.end(), t), tasks.end());
}

void TaskManager::remove_task_at(int index){
    tasks.erase(tasks.begin() + index);
}

std::vector<Task>& TaskManager::get_tasks(){
    return tasks;
}

// Load tasks from file into a vector
void TaskManager::load_tasks(){
    char buffer[task_description_length];
    
    std::ifstream tasks_file(TaskManager::tasks_file_path.c_str());

    std::cout << TaskManager::tasks_file_path << std::endl;

    if(!tasks_file.is_open()){
        std::cout << "ERROR: Tasks file does not exists" << std::endl;
        return;
    }

    while(tasks_file.getline(buffer, sizeof(buffer))){
        Task t(buffer);
        tasks.push_back(t);
    }
}

void TaskManager::save(){   
    std::ofstream task_file;
    task_file.open(TaskManager::tasks_file_path);

    for(Task& t : tasks){
        std::string task = t.get_description();
        task_file << t.get_description() << std::endl;
    }

    task_file.close();
}