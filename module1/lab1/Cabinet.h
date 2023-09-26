//
// Created by Павел on 16.09.2023.
//

#ifndef LAB1_CABINET_H
#define LAB1_CABINET_H

#include "Vector3.h"

class Cabinet{
private:
    std::string material;
    Vector3 position;
    Vector3 size;

public:
    const std::string get_material() const;
    void set_material(std::string value);

    const Vector3 get_position() const;
    void set_position(const Vector3 &value);

    const Vector3 get_size() const;
    void set_size(const Vector3 &value);

    Cabinet();
    Cabinet(std::string material, const Vector3 &position, const Vector3 &size);
    Cabinet(const Cabinet &cabinet);

    void show();

    bool isCollision(const Cabinet &cabinet);


};

#endif //LAB1_CABINET_H
