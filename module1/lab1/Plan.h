//
// Created by Павел on 02.11.2023.
//

#ifndef LAB1_PLAN_H
#define LAB1_PLAN_H

#include <iostream>

#include "Vector3.h"
#include "Entity.h"

class Plan {
private:
    Vector3 size;
    std::vector<Entity*> entities;

public:
    Vector3 get_size() const;
    void set_size(const Vector3 &value);

    Plan();
    Plan(const Vector3 &size);
    Plan(const Vector3 &size, const std::vector<Entity*> &entities);
    Plan(const Plan &plan);

    std::vector<Entity*> get_entities() const;
    void set_entities(const std::vector<Entity*> &entities);

    void addEntity(Entity *entity);
    void removeEntityByNumber(int number);
    bool check();

    void show() const;
};


#endif //LAB1_PLAN_H
