//
// Created by Павел on 16.09.2023.
//

#include <iostream>

#include "Cabinet.h"

const Vector3 Cabinet::get_position() const {
    return position;
}

void Cabinet::set_position(const Vector3 &value) {
    position = value;
}

const Vector3 Cabinet::get_size() const {
    return size;
}

void Cabinet::set_size(const Vector3 &value) {
    if(value.get_x()>0 && value.get_y()>0 && value.get_z()>0){
        size =  Vector3(value);
    }
    else{
        std::cout<<"Inappropriate value";
    }
}

const std::string Cabinet::get_material() const {
    return material;
}

void Cabinet::set_material(std::string value) {
    material = value;
}


Cabinet::Cabinet(){
    material="wood";
    position = Vector3();
    size = Vector3(1, 1, 1);
}

Cabinet::Cabinet(std::string material, const Vector3 &position, const Vector3 &size) {
    this->material = material;
    this->position = Vector3(position);
    this->size = Vector3(size);
}

Cabinet::Cabinet(const Cabinet &cabinet) {
    this->material = cabinet.material;
    this->position = Vector3(cabinet.position);
    this->size = Vector3(cabinet.size);
}

void Cabinet::show() {
    std::cout<<"Cabinet"<<std::endl;
    std::cout<<"Material is "<<get_material()<<std::endl;
    std::cout<<"Position is ";
    get_position().show();
    std::cout<<std::endl;

    std::cout<<"Size is ";
    get_size().show();
    std::cout<<std::endl;
    std::cout<<std::endl;
}

bool Cabinet::isCollision(const Cabinet &cabinet) {
    return (
            ((abs(get_position().get_x() - cabinet.position.get_x()) <
                get_size().get_x() + cabinet.size.get_x()) &&
            (abs(get_position().get_y() - cabinet.position.get_y()) <
                get_size().get_y() + cabinet.size.get_y()) &&
            (abs(get_position().get_z() - cabinet.position.get_z()) <
                get_size().get_z() + cabinet.size.get_z())) ||
                    (
                    (get_position().distance(cabinet.get_position())<2 &&
                        get_material()!=cabinet.get_material()) ||
                    (get_material()==cabinet.get_material())
                    )
            );
}

