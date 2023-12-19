//
// Created by Павел on 19.12.2023.
//

#include "Subtask.h"

#include <utility>

Subtask::Subtask() : Task() {

}

Subtask::Subtask(const std::string &name, int hours, int priority, ComplexTask* complexTask) : Task(name, hours, priority) {
    this->complexTask = complexTask;
}

Subtask::Subtask(const Subtask &subtask): Task(subtask) {
    this->complexTask = subtask.complexTask;
}

TaskType Subtask::getType() const {
    return TaskType::TSubTask;
}

void Subtask::assign(std::shared_ptr<Actor> actor) {
    Task::assign(actor);
    complexTask->assign(actor);
}

void Subtask::complete(std::shared_ptr<Actor> actor) {
    Task::complete(actor);
    complexTask->assign(actor);
}

void Subtask::work(std::shared_ptr<Actor> actor) {
    Task::work(actor);
    complexTask->assign(actor);
}

