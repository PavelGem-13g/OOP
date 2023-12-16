//
// Created by Павел on 14.12.2023.
//

#ifndef PROJECT_ACTOR_H
#define PROJECT_ACTOR_H


#include <string>

class Actor {
public:
    Actor(std::string  name, int weeklyHours);

    const std::string& getName() const;

    int getHours() const;

    void show();

    void changeHours(int delta);
private:
    std::string name;
    int hours;
};


#endif //PROJECT_ACTOR_H
