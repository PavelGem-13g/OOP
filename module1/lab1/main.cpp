#include <iostream>
#include <cassert>

#include "Cabinet.h"
#include "Appliance.h"
#include "Vector3.h"

int main() {

    Cabinet test = Cabinet();
    assert(
            test.get_material()=="wood"&&

            test.get_position().get_x()==0 &&
            test.get_position().get_y()==0 &&
            test.get_position().get_z()==0 &&

            test.get_size().get_x()==1 &&
            test.get_size().get_y()==1 &&
            test.get_size().get_z()==1
    );

    test.set_material("wood");
    test.set_position( Vector3(1, 2, 3));
    test.set_size( Vector3(4, 5, 6));

    assert(
            test.get_material()=="wood" &&
            test.get_position().get_x()==1 &&
            test.get_position().get_y()==2 &&
            test.get_position().get_z()==3 &&

            test.get_size().get_x()==4 &&
            test.get_size().get_y()==5 &&
            test.get_size().get_z()==6
    );

    Cabinet test2 = Cabinet(
            Vector3(1, 2, 3),
            Vector3(4, 5, 6),
            "wood");

    assert(
            test2.get_material() == "wood" &&
            test2.get_position().get_x()==1 &&
            test2.get_position().get_y()==2 &&
            test2.get_position().get_z()==3 &&

            test2.get_size().get_x()==4 &&
            test2.get_size().get_y()==5 &&
            test2.get_size().get_z()==6
    );

    Cabinet test3 = Cabinet(test2);
    assert(
            test3.get_material()==test2.get_material() &&
            test3.get_position().get_x()==test2.get_position().get_x() &&
            test3.get_position().get_y()==test2.get_position().get_y() &&
            test3.get_position().get_z()==test2.get_position().get_z() &&

            test3.get_size().get_x()==test2.get_size().get_x() &&
            test3.get_size().get_y()==test2.get_size().get_y() &&
            test3.get_size().get_z()==test2.get_size().get_z()
    );


    Cabinet one = Cabinet(
            Vector3(),
            Vector3(1, 1, 1),
            "wood");

    Cabinet two = Cabinet(
            Vector3(),
            Vector3(2, 2, 2),
            "metal");

    Cabinet three = Cabinet(
            Vector3(10, 10, 10),
            Vector3(1, 1,1),
            "plastic");

    Cabinet four = Cabinet(
            Vector3(1.5, 0, 0),
            Vector3(0.1, 0.1, 0.1),
            "plastic");

    assert(one.isCollision(two)== true);
    assert(one.isCollision(three)== false);
    assert(one.isCollision(four)== true);

    Appliance appliance = Appliance();
    assert(
            appliance.get_name()=="default"&&
            appliance.get_state()== false&&

            appliance.get_position().get_x()==0 &&
            appliance.get_position().get_y()==0 &&
            appliance.get_position().get_z()==0 &&

            appliance.get_size().get_x()==1 &&
            appliance.get_size().get_y()==1 &&
            appliance.get_size().get_z()==1
    );

    appliance.set_name("Fridge");
    appliance.changeState();
    appliance.set_position( Vector3(1, 2, 3));
    appliance.set_size( Vector3(4, 5, 6));

    assert(
            appliance.get_name() == "Fridge" &&
            appliance.get_state() == true &&

            appliance.get_position().get_x()==1 &&
            appliance.get_position().get_y()==2 &&
            appliance.get_position().get_z()==3 &&

            appliance.get_size().get_x()==4 &&
            appliance.get_size().get_y()==5 &&
            appliance.get_size().get_z()==6
    );

    Appliance appliance2 = Appliance(
            Vector3(1, 2, 3),
            Vector3(4, 5, 6),
            "Fridge",
            true);

    assert(
            appliance2.get_name() == "Fridge" &&
            appliance2.get_state() == true &&

            appliance2.get_position().get_x()==1 &&
            appliance2.get_position().get_y()==2 &&
            appliance2.get_position().get_z()==3 &&

            appliance2.get_size().get_x()==4 &&
            appliance2.get_size().get_y()==5 &&
            appliance2.get_size().get_z()==6
    );

    Appliance appliance3 = Appliance(appliance2);
    assert(
            appliance3.get_name()==appliance2.get_name() &&
            appliance3.get_state()==appliance2.get_state() &&
            appliance3.get_position().get_x()==appliance2.get_position().get_x() &&
            appliance3.get_position().get_y()==appliance2.get_position().get_y() &&
            appliance3.get_position().get_z()==appliance2.get_position().get_z() &&

            appliance3.get_size().get_x()==appliance2.get_size().get_x() &&
            appliance3.get_size().get_y()==appliance2.get_size().get_y() &&
            appliance3.get_size().get_z()==appliance2.get_size().get_z()
    );

    Appliance applianceThree = Appliance(
            Vector3(10, 10, 10),
            Vector3(1, 1,1),
            "Fridge",
            false);

    Appliance applianceTwo = Appliance(
            Vector3(),
            Vector3(2, 2, 2),
            "Fridge",
            false);

    Appliance applianceFour = Appliance(
            Vector3(1.5, 0, 0),
            Vector3(0.1, 0.1, 0.1),
            "Fridge",
            false);

    assert(one.isCollision(applianceTwo) == true);
    assert(one.isCollision(applianceThree) == false);
    assert(one.isCollision(applianceFour) == false);

    std::cout<<"All testes has completed successfully"<<std::endl;

    return 0;
}
