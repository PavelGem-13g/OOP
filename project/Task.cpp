//
// Created by Павел on 14.12.2023.
//

#include "Task.h"

Task::Task(int priority, int hours): priority(priority), hours(hours)  {

}

void Task::assign() {
    std::cout << "Assigning " << name << " " << priority << " for " << hours << " hours." << std::endl;
    progress = TaskProgressType::TWork;
}

int Task::getPriority() const  {
    return priority;
}

int Task::getHours() const {
    return hours;
}

TaskType Task::getType() const {
    return TaskType::TTask;
}

TaskProgressType Task::getProgress() const {
    return progress;
}

std::string Task::getName() const {
    return name;
}

Task::Task(const std::string &name, int hours, int priority) {
    this->name = name;
    this->hours = hours;
    this->priority = priority;
    this->progress = TaskProgressType::TFree;
}

Task::Task(const Task &task) {
    this->name = task.name;
    this->hours = task.hours;
    this->priority = task.priority;
    this->progress = task.progress;
}

void Task::show() {
    //std::cout<<getName()<<std::endl;
    std::cout<<"Name "<<name<<"\tHours "<<hours<<"\tPriority "<<priority<<"\tType "<<GetTypeString(getType())<<std::endl;
}

Task::Task() {
    this->name = "";
    this->hours = 0;
    this->priority = 0;
    this->progress = TaskProgressType::TFree;
}
