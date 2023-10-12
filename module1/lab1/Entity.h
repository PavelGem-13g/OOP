//
// Created by Павел on 12.10.2023.
//

#ifndef LAB1_ENTITY_H
#define LAB1_ENTITY_H

#include "Vector3.h"

class Entity {
protected:
    Vector3 position;
    Vector3 size;
public:
    const Vector3 get_position() const;
    void set_position(const Vector3 &value);

    const Vector3 get_size() const;
    void set_size(const Vector3 &value);

    Entity();
    Entity(const Vector3 &position, const Vector3 &size);
    Entity(const Entity &entity);

    virtual std::string type() const;
    virtual void show();

    virtual bool isCollision(const Entity &entity);
};


#endif //LAB1_ENTITY_H
