//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H


#include <vector>

#include "Actor.h"
#include "Task.h"
#include "Subtask.h"

class Project {
public:
    void addActor(const Actor& actor);

    void addTask(Task *task);
    void addTask(const std::string& name, int hours, int priority);

    void splitTasks();

    void distributeTasks();

    std::vector<Actor> getActors() const;
    std::vector<Task*> getTasks() const;

private:
    int threshold;

    std::vector<Actor> actors;
    std::vector<Task*> tasks;

    void splitTask(Task& task);

};


#endif //PROJECT_PROJECT_H
