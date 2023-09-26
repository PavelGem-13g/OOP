//
// Created by Павел on 16.09.2023.
//

#include <iostream>

#include "Vector3.h"

const float Vector3::get_x() const {
    return x;
}

void Vector3::set_x(int value) {
    x = value;
}

const float Vector3::get_y() const {
    return y;
}

void Vector3::set_y(int value) {
    y = value;
}

const float Vector3::get_z() const {
    return z;
}

void Vector3::set_z(int value) {
    z = value;
}

Vector3::Vector3() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(const Vector3 &vector3) {
    this->x = vector3.x;
    this->y = vector3.y;
    this->z = vector3.z;
}

void Vector3::show() const {
    std::cout<<"x = "<<get_x()<<" y = "<<get_y()<<" z = "<<get_z();
}

float Vector3::distance(const Vector3 &vector3) const {
    return sqrt(
            pow(get_x()-vector3.get_x(), 2)
            + pow(get_y()-vector3.get_y(), 2)
            + pow(get_z()-vector3.get_z(), 2)
            );
}

