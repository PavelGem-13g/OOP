//
// Created by Павел on 19.12.2023.
//

#ifndef PROJECT_SUBTASK_H
#define PROJECT_SUBTASK_H

#include "Task.h"

class Subtask : public Task{
public:
    TaskType getType() const override;
    void assign(std::shared_ptr<Actor> actor) override;

protected:
    void complete(std::shared_ptr<Actor> actor) override;
    void work(std::shared_ptr<Actor> actor) override;

};


#endif //PROJECT_SUBTASK_H
