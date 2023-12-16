//
// Created by Павел on 14.12.2023.
//

#include "Task.h"

Task::Task(int priority, int hours): priority(priority), hours(hours)  {

}

void Task::assign(Actor &actor) {
    if(actor.getHours()>=hours){
        progress = TaskProgressType::TComplete;
        int deltaHours = hours;
        changeHours(-deltaHours);
        std::cout<<"Decrease "<<actor.getHours()<<" "<<-deltaHours<<std::endl;
        actor.changeHours(-deltaHours);
    } else{
        progress = TaskProgressType::TWork;
        changeHours(-actor.getHours());
        actor.changeHours(-actor.getHours());
    }
    std::cout << "Assigning " << name << "\tfor " << hours << " hours with progress "<< GetTaskProgressTypeString(progress) << std::endl;
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
    std::cout << "Name " << name << "\tHours " << hours << "\tPriority " << priority << "\tType " << GetTaskTypeString(
            getType()) << std::endl;
}

Task::Task() {
    this->name = "";
    this->hours = 0;
    this->priority = 0;
    this->progress = TaskProgressType::TFree;
}

bool Task::check(const Actor &actor) {
    return actor.getHours() > 0;
}

void Task::complete(Actor &actor) {
    progress = TaskProgressType::TComplete;
    changeHours(-hours);
    actor.changeHours(-hours);
}

void Task::changeHours(int delta) {
    hours+=delta;
}

void Task::work(Actor &actor) {
    progress = TaskProgressType::TWork;
    changeHours(-actor.getHours());
    actor.changeHours(-actor.getHours());
}
