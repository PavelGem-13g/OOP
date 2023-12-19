//
// Created by Павел on 14.12.2023.
//

#include "Actor.h"

#include <iostream>
#include <utility>

Actor::Actor(std::string name, int weeklyHours) : name(std::move(name)), hours(weeklyHours) {

}

const std::string &Actor::getName() const {
    return name;
}

int Actor::getHours() const {
    return hours;
}

void Actor::show() const{
    std::cout<<"Name "<<name<<"\tHours "<<hours<<"\t"<<std::endl;
}

void Actor::changeHours(int delta) {
    hours+=delta;
}

Actor::Actor() {
    name = "Actor";
    hours = 10;
}

Actor::Actor(const Actor &actor) {
    this->name = actor.name;
    this->hours = actor.hours;
}
