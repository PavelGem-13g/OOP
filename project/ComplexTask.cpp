//
// Created by Павел on 15.12.2023.
//

#include <cmath>

#include "ComplexTask.h"

std::vector<std::shared_ptr<Task>> ComplexTask::getSubtasks() const{
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
        subtask->show();
    }
}

ComplexTask::ComplexTask(const std::string &name, int hours, int priority) : Task(name, hours, priority) {
    splitTasks();
}

void ComplexTask::splitTasks() {
    int hours = std::floor(this->hours*0.9);
    int taskNumber = 1;
    int threshold = 5;
    while (hours > 0){
        std::string name = this->getName()+" - "+std::to_string(taskNumber);
        auto tempTask = std::make_shared<Task>(name, std::min(threshold, hours), this->getPriority() + 1);
        subtasks.push_back(tempTask);
        hours-=std::min(threshold, hours);
        taskNumber+=1;
    }
    std::string name = this->getName()+" - Collecting results";
    auto tempTask = std::make_shared<Task>(name, static_cast<int>(std::ceil(this->hours * 0.1)),
                                           this->getPriority() - 1);
    subtasks.push_back(std::move(tempTask));
}

ComplexTask::ComplexTask() :Task() {
    splitTasks();
}

void ComplexTask::assign(std::shared_ptr<Actor> actor) {
    //Task::assign(actor);
}

void ComplexTask::work(std::shared_ptr<Actor> actor) {
    Task::work(actor);
}

void ComplexTask::complete(std::shared_ptr<Actor> actor) {
    Task::complete(actor);
}

