//
// Created by Павел on 14.12.2023.
//

#include "Task.h"

Task::Task() {
    this->name = "Name";
    this->hours = 0;
    this->priority = 0;
    this->progress = TaskProgressType::TFree;
}

Task::Task(const std::string &name, int hours, int priority) {
    this->name = name;
    this->hours = hours;
    this->priority = priority;
    this->progress = TaskProgressType::TFree;
}

Task::Task(int priority, int hours): priority(priority), hours(hours)  {

}

Task::Task(const std::string &name, int hours, int priority, TaskProgressType progress) :
        Task(name, hours, priority){
    this->progress = progress;
}

Task::Task(const Task &task) {
    this->name = task.name;
    this->hours = task.hours;
    this->priority = task.priority;
    this->progress = task.progress;
}

int Task::getPriority() const  {
    return priority;
}

int Task::getHours() const {
    return hours;
}

std::string Task::getName() const {
    return name;
}

TaskType Task::getType() const {
    return TaskType::TTask;
}

std::set<std::shared_ptr<Actor>> Task::getActors() const {
    return actors;
}

TaskProgressType Task::getProgress() const {
    return progress;
}

void Task::show() const {
    std::cout << "Name " << name << "\tHours " << hours << "\tPriority " << priority << "\tType " << GetTaskTypeString(
            getType()) << "\tProgress "<< GetTaskProgressTypeString(getProgress()) << std::endl;
    for(auto& actor:actors){
        std::cout<<"\t"<<actor->getName();
    }
    std::cout<<std::endl;
}

bool Task::check(const std::shared_ptr<Actor> actor) {
    return actor->getHours() > 0;
}

void Task::assign(std::shared_ptr<Actor> actor) {
    actors.insert(actor);
    if(actor->getHours()>=hours){
        complete(actor);
    } else{
        work(actor);
    }
}

void Task::changeHours(int delta) {
    hours+=delta;
}

void Task::complete(std::shared_ptr<Actor> actor) {
    progress = TaskProgressType::TComplete;
    int deltaHours = hours;
    changeHours(-deltaHours);
    actor->changeHours(-deltaHours);
}

void Task::work(std::shared_ptr<Actor> actor) {
    progress = TaskProgressType::TWork;
    int deltaHours = actor->getHours();
    changeHours(-deltaHours);
    actor->changeHours(-deltaHours);
}

