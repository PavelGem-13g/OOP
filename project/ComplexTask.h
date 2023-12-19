//
// Created by Павел on 15.12.2023.
//

#ifndef PROJECT_COMPLEXTASK_H
#define PROJECT_COMPLEXTASK_H


#include "Task.h"

class ComplexTask final : public Task{
public:
    ComplexTask();
    ComplexTask(const std::string &name, int hours, int priority);
    ComplexTask(const ComplexTask &complexTask);
    ~ComplexTask() = default;

    std::vector<std::shared_ptr<Task>> getSubtasks() const;

    TaskType getType() const override;

    void assign(std::shared_ptr<Actor> actor) override;
    void show() const override;
    void addToProject(int threshold);

protected:
    void work(std::shared_ptr<Actor> actor) override;
    void complete(std::shared_ptr<Actor> actor) override;

private:
    int threshold;
    std::vector<std::shared_ptr<Task>> subtasks;

    void splitTasks();
};


#endif //PROJECT_COMPLEXTASK_H
