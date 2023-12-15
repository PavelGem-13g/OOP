//
// Created by Павел on 15.12.2023.
//

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
    int hours = this->hours;
    int taskNumber = 1;
    int threshold = 4;
    while (hours > 0){
        std::string name = this->getName()+" - "+std::to_string(taskNumber);
        Task tempTask = Task{name, taskNumber*threshold, this->getPriority()+2};
        subtasks.push_back(tempTask);
        hours-=threshold;
        taskNumber+=1;
    }
}

ComplexTask::ComplexTask() :Task() {
    splitTasks();
}

