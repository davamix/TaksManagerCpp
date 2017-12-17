#include <iostream>
#include "include/task.h"
#include "include/task_manager.h"

// https://hackernoon.com/error-handling-in-c-or-why-you-should-use-eithers-in-favor-of-exceptions-and-error-codes-f0640912eb45
//
// template<class Left, class Right> 
// struct Either{
//     // A union is a special class type that can hold only one of its non-static data members at a time.
//     // http://en.cppreference.com/w/cpp/language/union
//     union{
//         Left leftValue;
//         Right rightValue;
//     };

//     bool isLeft;
// };

TaskManager tm;

void show_debug(std::string message){
    std::cout << "### DEBUG " << message << " ###" << std::endl;
}

int to_int(std::string value){
    int number;

    try{    
        number = std::stoi(value);
    }catch(std::invalid_argument&){
        std::cout << "ERROR: " << value << " is not a number." << std::endl;
        return -1;
    }

    return number;
}

std::string show_menu(){
    std::string option;

    std::cout << "1. Show all tasks" << std::endl;
    std::cout << "2. Add new task" << std::endl;
    std::cout << "3. Remove task" << std::endl;
    std::cout << "4. Save" << std::endl;
    std::cout << "0. Exit" << std::endl;

    std::cout << ">> ";
    std::getline(std::cin, option);

    return option;
}

void show_tasks(TaskManager& manager){
    show_debug("show_tasks");
    const std::vector<Task>& tasks = manager.get_tasks();

    int x = 1; // index task
    for(Task t: tasks){
        std::cout << x << ". " << t.get_description() << std::endl;
        x++;
    }

    show_debug("End show_tasks");
}

void add_task(TaskManager& manager){
    std::string description;
    std::cout << "Tasks description: ";
    std::getline(std::cin, description);

    Task t(description);
    manager.add_task(t);
}

void remove_task(TaskManager& manager){
    std::string option;
    std::cout << "Choose the task number to delete: ";
    std::getline(std::cin, option);

    int task_position = to_int(option);

    if(task_position <= 0)
        return;

    manager.remove_task_at(task_position - 1);
}

void save_task(TaskManager& manager){
    //show_debug("Saving tasks");
    manager.save();
}


int main(){

    // Declared out of the main function. https://stackoverflow.com/a/27825354
    //TaskManager tm;

    int valid_option;

    do{
        std::string option = show_menu();
        valid_option = to_int(option);

        switch(valid_option){
            case 1:
                show_tasks(tm);
                break;
            case 2:
                add_task(tm);
                break;
            case 3:
                remove_task(tm);
                break;
            case 4:
                save_task(tm);
                break;
        }
    }while(valid_option != 0);

    //return 0; // not mandatory, the compiler add it automatically.
}