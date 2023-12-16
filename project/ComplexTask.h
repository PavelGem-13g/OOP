//
// Created by Павел on 15.12.2023.
//

#ifndef PROJECT_COMPLEXTASK_H
#define PROJECT_COMPLEXTASK_H


#include "Task.h"

class ComplexTask : public Task{
public:
    ComplexTask();
    ComplexTask(const Task &task);
    ComplexTask(const std::string &name, int hours, int priority);
    std::vector<Task*> getSubtasks() const;

    TaskType getType() const override;

    void show() override;
private:
    std::vector<Task*> subtasks;

    void splitTasks();
};


#endif //PROJECT_COMPLEXTASK_H
