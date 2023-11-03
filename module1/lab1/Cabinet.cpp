//
// Created by Павел on 16.09.2023.
//

#include <iostream>

#include "Cabinet.h"
#include "EntityType.h"

std::string Cabinet::get_material() const {
    return material;
}

void Cabinet::set_material(const std::string &value) {
    material = value;
}

Cabinet::Cabinet():Entity(){
    material="wood";
}

Cabinet::Cabinet(const Vector3 &position, const Vector3 &size, const std::string &material):
Entity(position, size) {
    this->material = material;
}

Cabinet::Cabinet(const Cabinet &cabinet): Entity((Entity&) cabinet) {
    this->material = cabinet.material;
}

EntityType Cabinet::type() const {
    return EntityType::TCabinet;
}

void Cabinet::show() const {
    Entity::show();
    std::cout<<"Material is "<<get_material()<<std::endl;
    std::cout<<std::endl;
}

bool Cabinet::isCollision(const Entity &entity) {
    return (
            (Entity::isCollision(entity)) ||
                    ( entity.type()== EntityType::TCabinet&&(
                    (get_position().distance(((Cabinet &)entity).get_position())<2 &&
                        get_material()!=((Cabinet &)entity).get_material()) ||
                    (get_material()==((Cabinet &)entity).get_material())
                    ))
            );
}

