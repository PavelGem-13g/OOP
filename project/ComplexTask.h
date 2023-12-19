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
    std::vector<std::shared_ptr<Task>> getSubtasks() const;

    TaskType getType() const override;

    void assign(std::shared_ptr<Actor> actor) override;

    void show() override;

protected:
    void work(std::shared_ptr<Actor> actor) override;
    void complete(std::shared_ptr<Actor> actor) override;

private:
    std::vector<std::shared_ptr<Task>> subtasks;

    void splitTasks();
};


#endif //PROJECT_COMPLEXTASK_H
