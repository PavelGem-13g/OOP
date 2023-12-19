//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H


#include <vector>

#include "Actor.h"
#include "Task.h"

class Project final {
public:
    Project();
    Project(int threshold);
    Project(const Project &project);
    ~Project() = default;

    void addActor(const std::shared_ptr<Actor> actor);
    void addTask(const std::shared_ptr<Task> task);
    void distributeTasks();

    std::vector<std::shared_ptr<Actor>> getActors() const;
    std::vector<std::shared_ptr<Task>> getTasks() const;

    template<class Compare>
    void sortTasks(const Compare &comparator);
    void sortTasksDescending();

    template<class Compare>
    void sortActors(const Compare &comparator);
    void sortActorsDescending();

    std::vector<std::shared_ptr<Task>> getSimpleTasks();

    void show() const;

private:
    int threshold;

    std::vector<std::shared_ptr<Actor>> actors;
    std::vector<std::shared_ptr<Task>> tasks;
};


#endif //PROJECT_PROJECT_H
