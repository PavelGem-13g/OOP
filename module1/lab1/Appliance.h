//
// Created by Павел on 12.10.2023.
//

#ifndef LAB1_APPLIANCE_H
#define LAB1_APPLIANCE_H

#include <string>
#include "Entity.h"

class Appliance final : public Entity{
private:
    std::string name;
    bool state;
public:
    const std::string get_name() const;
    void set_name(std::string value);
    const bool get_state() const;
    void set_state(bool state);

    Appliance();
    Appliance(const Vector3 &position, const Vector3 &size, std::string name,bool state);
    Appliance(const Appliance &appliances);

    std::string type() const override;
    void show() override;

    void changeState();
};


#endif //LAB1_APPLIANCE_H
