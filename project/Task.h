//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_TASK_H
#define PROJECT_TASK_H


#include <vector>
#include <iostream>
#include <string>
#include <set>

#include "TaskType.h"
#include "TaskProgressType.h"
#include "Actor.h"

class Task : public std::enable_shared_from_this<Task>{
public:
    Task();

    Task(int priority, int hours);

    Task(const Task &task);

    Task(const std::string &name, int hours, int priority);


    int getPriority() const;

    int getHours() const;

    std::string getName() const;

    virtual TaskType getType() const;

    TaskProgressType getProgress() const;

    virtual void show();

    virtual bool check(const std::shared_ptr<Actor> actor);
    virtual void assign(std::shared_ptr<Actor> actor);


    void changeHours(int delta);

protected:
    std::string name;
    int hours;
    int priority;
    TaskProgressType progress;
    std::set<std::shared_ptr<Actor>> actors;

    virtual void complete(std::shared_ptr<Actor> actor);
    virtual void work(std::shared_ptr<Actor> actor);
};


#endif //PROJECT_TASK_H
