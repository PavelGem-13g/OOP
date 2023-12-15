//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_ACTOR_H
#define PROJECT_ACTOR_H


#include <string>
#include "Task.h"

class Actor {
public:
    Actor(const std::string& name, int weeklyHours);

    const std::string& getName() const;

    int getHours() const;

    void assignTask(Task task);

    void show();
private:
    std::string name;
    int hours;
};


#endif //PROJECT_ACTOR_H
