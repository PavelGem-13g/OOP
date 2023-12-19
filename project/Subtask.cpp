//
// Created by Павел on 19.12.2023.
//

#include "Subtask.h"

#include <utility>

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

Subtask::Subtask() {

}

Subtask::Subtask(const std::string &name, int hours, int priority, std::shared_ptr<ComplexTask> complexTask) : Task(name, hours, priority) {
    this->complexTask = std::move(complexTask);
}

