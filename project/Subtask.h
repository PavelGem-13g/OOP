//
// Created by Павел on 19.12.2023.
//

#ifndef PROJECT_SUBTASK_H
#define PROJECT_SUBTASK_H

#include "Task.h"
#include "ComplexTask.h"

class Subtask : public Task{
public:
    Subtask();
    Subtask(const std::string &name, int hours, int priority, std::shared_ptr<ComplexTask> complexTask);
    Subtask(const Subtask &subtask);

    TaskType getType() const override;
    void assign(std::shared_ptr<Actor> actor) override;

protected:
    void complete(std::shared_ptr<Actor> actor) override;
    void work(std::shared_ptr<Actor> actor) override;
    std::shared_ptr<ComplexTask> complexTask;
};


#endif //PROJECT_SUBTASK_H
