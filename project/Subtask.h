//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_SUBTASK_H
#define PROJECT_SUBTASK_H


#include "Task.h"

class Subtask : public Task {
public:
    Subtask(int priority, int hours) : Task(priority, hours) {}

    void assign() const override;

    TaskType getType() const override;
};


#endif //PROJECT_SUBTASK_H
