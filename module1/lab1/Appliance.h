//
// Created by Павел on 12.10.2023.
//

#ifndef LAB1_APPLIANCE_H
#define LAB1_APPLIANCE_H

#include "Entity.h"

class Appliance final : public Entity{
private:
    std::string name;
    bool state;
public:
    std::string get_name() const;
    void set_name(std::string value);
    bool get_state() const;
    void set_state(bool state);

    Appliance();
    Appliance(const Vector3 &position, const Vector3 &size, std::string name,bool state);
    Appliance(const Appliance &appliances);

    EntityType type() const override;
    void show() const override;

    void changeState();
};


#endif //LAB1_APPLIANCE_H
