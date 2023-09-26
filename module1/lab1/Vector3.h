//
// Created by Павел on 16.09.2023.
//

#ifndef LAB1_VECTOR3_H
#define LAB1_VECTOR3_H

class Vector3{
private:
    float x;
    float y;
    float z;

public:
    const float get_x() const;
    void set_x(int value);

    const float get_y() const;
    void set_y(int value);

    const float get_z() const;
    void set_z(int value);

    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector3 &vector3);

    float distance(const Vector3 &vector3) const;

    void show() const;
};

#endif //LAB1_VECTOR3_H
