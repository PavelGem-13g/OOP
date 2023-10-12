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
    const std::string get_material() const;
    void set_material(std::string value);

    Cabinet();
    Cabinet(const Vector3 &position, const Vector3 &size, std::string material);
    Cabinet(const Cabinet &cabinet);

    std::string type() const override;
    void show() override;

    bool isCollision(const Entity &entity);
};

#endif //LAB1_CABINET_H
