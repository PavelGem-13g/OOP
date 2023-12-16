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
#include "Actor.h"

class Task {
public:
    Task();

    Task(int priority, int hours);

    Task(const Task &task);

    Task(const std::string &name, int hours, int priority);

    virtual void assign(Actor &actor);

    int getPriority() const;

    int getHours() const;

    std::string getName() const;

    virtual TaskType getType() const;

    TaskProgressType getProgress() const;

    virtual void show();

    virtual bool check(const Actor &actor);

    void changeHours(int delta);

protected:
    std::string name;
    int hours;
    int priority;
    TaskProgressType progress;

    virtual void complete(Actor &actor);
    virtual void work(Actor &actor);
};


#endif //PROJECT_TASK_H
