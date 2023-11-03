//
// Created by Павел on 12.10.2023.
//

#include <iostream>
#include "Entity.h"

Vector3 Entity::get_position() const {
    return position;
}

void Entity::set_position(const Vector3 &value) {
    position = value;
}

Vector3 Entity::get_size() const {
    return size;
}

void Entity::set_size(const Vector3 &value) {
    if(value.get_x()>0 && value.get_y()>0 && value.get_z()>0){
        size =  Vector3(value);
    }
    else{
        std::cout<<"Inappropriate value";
    }
}

Entity::Entity() {
    position = Vector3();
    size = Vector3(1, 1, 1);
}

Entity::Entity(const Vector3 &position, const Vector3 &size) {
    this->position = Vector3(position);
    this->size = Vector3(size);
}

Entity::Entity(const Entity &entity) {
    this->position = Vector3(entity.position);
    this->size = Vector3(entity.size);
}


EntityType Entity::type() const {
    return EntityType::TEntity;
}

void Entity::show() const{
    std::cout<<GetEntityTypeString(type())<<std::endl;
    std::cout<<"Position is ";
    get_position().show();
    std::cout<<std::endl;

    std::cout<<"Size is ";
    get_size().show();
    std::cout<<std::endl;
}

bool Entity::isCollision(const Entity &entity) {
    return
            ((abs(get_position().get_x() - entity.position.get_x()) <
              get_size().get_x() + entity.size.get_x()) &&
             (abs(get_position().get_y() - entity.position.get_y()) <
              get_size().get_y() + entity.size.get_y()) &&
             (abs(get_position().get_z() - entity.position.get_z()) <
              get_size().get_z() + entity.size.get_z()));
}
