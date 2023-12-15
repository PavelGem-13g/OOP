//
// Created by Павел on 14.12.2023.
//

#include "Subtask.h"

void Subtask::assign() const {
    std::cout << "Assigning subtask with priority " << priority
              << " for " << hours << " hours." << std::endl;
}

TaskType Subtask::getType() const {
    return TaskType::TSubTask;
}
