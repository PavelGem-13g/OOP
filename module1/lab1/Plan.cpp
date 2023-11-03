//
// Created by Павел on 02.11.2023.
//

#include "Plan.h"

#include "EntityType.h"

bool Plan::check() {
    bool result = true;
    for (int i = 0; i < entities.size(); ++i) {
        for (int j = i + 1; j < entities.size(); ++j) {
            if(entities[i].isCollision(entities[j])){
                result = false;
                break;
            }
        }
        if(result){
            break;
        }
    }

    for (int i = 0; i < entities.size(); ++i) {
        if(entities[i].type()==EntityType::TAppliance){
            if(entities[i].get_position().get_y()==0){
                result = false;
                break;
            }
        }
    }

    for(auto item: entities){
        double min_x = 0;
        double max_x = size.get_x();
        double min_y = 0;
        double max_y = size.get_y();
        double min_z = 0;
        double max_z = size.get_z();

        auto pos = item.get_position();
        auto size = item.get_size();

        double other_min_x = pos.get_x() - size.get_x();
        double other_max_x = pos.get_x() + size.get_x();
        double other_min_y = pos.get_y() - size.get_y();
        double other_max_y = pos.get_y() + size.get_y();
        double other_min_z = pos.get_z() - size.get_z();
        double other_max_z = pos.get_z() + size.get_z();

        if(min_x >= other_min_x && max_x <= other_max_x &&
           min_y >= other_min_y && max_y <= other_max_y &&
           min_z >= other_min_z && max_z <= other_max_z){
            result = false;
            break;
        }
    }
    return result;
}

Vector3 Plan::get_size() const {
    return size;
}

void Plan::set_size(const Vector3 &value) {
    if(value.get_x()>0 && value.get_y()>0 && value.get_z()>0){
        size =  Vector3(value);
    }
    else{
        std::cout<<"Inappropriate value";
    }
}

std::vector<Entity> Plan::get_entities() const {
    return entities;
}

void Plan::addEntity(const Entity &entity) {
    entities.push_back(entity);
}

Plan::Plan() {
    size = Vector3(1, 1, 1);
    entities = std::vector<Entity>();
}

Plan::Plan(const Vector3 &size, const std::vector<Entity> &entities) {
    this->size = size;
    this->entities = entities;
}

Plan::Plan(const Plan &plan) {
    this->size = Vector3(plan.size);
    std::copy(plan.entities.begin(), plan.entities.end(), this->entities.begin());
}

Plan::Plan(const Vector3 &size) {
    this->size = size;
    entities = std::vector<Entity>();
}

void Plan::set_entities(const std::vector<Entity> &entities) {
    this->entities = entities;
}
