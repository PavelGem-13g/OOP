//
// Created by Павел on 15.12.2023.
//

#include <cmath>

#include "ComplexTask.h"

std::vector<Task> ComplexTask::getSubtasks() const{
    return subtasks;
}

ComplexTask::ComplexTask(const Task &task) : Task(task) {
    splitTasks();
}

TaskType ComplexTask::getType() const {
    return TaskType::TComplexTask;
}

void ComplexTask::show() {
    Task::show();
    for (auto &subtask: subtasks) {
        subtask.show();
    }
}

ComplexTask::ComplexTask(const std::string &name, int hours, int priority) : Task(name, hours, priority) {
    splitTasks();
}

void ComplexTask::splitTasks() {
    int hours = std::ceil(this->hours*0.9);
    int taskNumber = 1;
    int threshold = 5;
    while (hours > 0){
        std::string name = this->getName()+" - "+std::to_string(taskNumber);
        Task tempTask = Task{name, std::min(threshold, hours), this->getPriority()+2};
        subtasks.push_back(tempTask);
        hours-=std::min(threshold, hours);
        taskNumber+=1;
    }
    std::string name = this->getName()+" - Collecting results";
    Task tempTask = Task{name, static_cast<int>(std::floor(this->hours*0.1)), this->getPriority()+1};
    subtasks.push_back(tempTask);
}

ComplexTask::ComplexTask() :Task() {
    splitTasks();
}

