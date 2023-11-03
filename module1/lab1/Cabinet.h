//
// Created by Павел on 16.09.2023.
//

#ifndef LAB1_CABINET_H
#define LAB1_CABINET_H

#include "Vector3.h"
#include "Entity.h"

class Cabinet final : public Entity{
private:
    std::string material;
public:
    std::string get_material() const;
    void set_material(const std::string &value);

    Cabinet();
    Cabinet(const Vector3 &position, const Vector3 &size, const std::string &material);
    Cabinet(const Cabinet &cabinet);

    EntityType type() const override;
    void show() const override;

    bool isCollision(const Entity &entity) override;
};

#endif //LAB1_CABINET_H
