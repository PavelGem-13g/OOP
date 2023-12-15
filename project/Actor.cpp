//
// Created by Павел on 14.12.2023.
//

#include "Actor.h"

Actor::Actor(const std::string &name, int weeklyHours) : name(name), hours(weeklyHours) {

}

const std::string &Actor::getName() const {
    return name;
}

int Actor::getHours() const {
    return hours;
}

void Actor::assignTask(Task task) {
    task.assign();
    hours -= task.getHours();
}

void Actor::show() {
    std::cout<<"Name "<<name<<"\tHours "<<hours<<"\t"<<std::endl;
}
