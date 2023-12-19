//
// Created by Павел on 19.12.2023.
//

#include "Subtask.h"

TaskType Subtask::getType() const {
    return TaskType::TSubTask;
}

void Subtask::assign(std::shared_ptr<Actor> actor) {
    Task::assign(actor);
}

void Subtask::complete(std::shared_ptr<Actor> actor) {
    Task::complete(actor);
}

void Subtask::work(std::shared_ptr<Actor> actor) {
    Task::work(actor);
}

