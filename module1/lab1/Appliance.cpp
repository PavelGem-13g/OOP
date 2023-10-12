//
// Created by Павел on 12.10.2023.
//

#include <iostream>
#include "Appliance.h"

const std::string Appliance::get_name() const {
    return name;
}

void Appliance::set_name(std::string value) {
    name = value;
}

const bool Appliance::get_state() const {
    return state;
}

void Appliance::set_state(bool state) {
    this->state = state;
}

Appliance::Appliance():
Entity() {
    name="default";
    this->state = false;
}

Appliance::Appliance(const Vector3 &position, const Vector3 &size, std::string name, bool state):
Entity(position, size)
{
    this->name = name;
    this->state = state;
}

Appliance::Appliance(const Appliance &appliances):
Entity((Entity&) appliances){
    this->name = appliances.name;
    this->state = appliances.state;
}

std::string Appliance::type() const {
    return "Appliance";
}

void Appliance::show() {
    Entity::show();
    std::cout<<"Name is "<<get_name()<<std::endl;
    std::cout<<"State is "<<get_state()<<std::endl;
    std::cout<<std::endl;
}

void Appliance::changeState() {
    state = !state;
}
