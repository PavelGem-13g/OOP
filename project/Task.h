//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_TASK_H
#define PROJECT_TASK_H


#include <vector>
#include <iostream>
#include <string>
#include "TaskType.h"
#include "TaskProgressType.h"

class Task {
public:
    Task();

    Task(int priority, int hours);

    Task(const Task &task);

    Task(const std::string &name, int hours, int priority);

    virtual void assign() const;

    int getPriority() const;

    int getHours() const;

    std::string getName() const;

    virtual TaskType getType() const;

    TaskProgressType getProgress() const;

    virtual void show();

protected:
    std::string name;
    int hours;
    int priority;
    TaskProgressType progress;
};


#endif //PROJECT_TASK_H
