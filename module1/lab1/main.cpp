#include <iostream>
#include <cassert>

#include "Vector3.h"

#include "Cabinet.h"
#include "Appliance.h"

#include "Plan.h"


int main() {

    Cabinet test = Cabinet();
    assert(test.get_material()=="wood");
    assert(test.get_position().get_x()==0);
    assert(test.get_position().get_y()==0);
    assert(test.get_position().get_z()==0);

    assert(test.get_size().get_x()==1);
    assert(test.get_size().get_y()==1);
    assert(test.get_size().get_z()==1);

    test.set_material("wood");
    test.set_position( Vector3(1, 2, 3));
    test.set_size( Vector3(4, 5, 6));

    assert(test.get_material()=="wood");
    assert(test.get_position().get_x()==1);
    assert(test.get_position().get_y()==2);
    assert(test.get_position().get_z()==3);

    assert(test.get_size().get_x()==4);
    assert(test.get_size().get_y()==5);
    assert(test.get_size().get_z()==6);

    Cabinet test2 = Cabinet(
            Vector3(1, 2, 3),
            Vector3(4, 5, 6),
            "wood");

    assert(test2.get_material() == "wood");
    assert(test2.get_position().get_x()==1);
    assert(test2.get_position().get_y()==2);
    assert(test2.get_position().get_z()==3);

    assert(test2.get_size().get_x()==4);
    assert(test2.get_size().get_y()==5);
    assert(test2.get_size().get_z()==6);

    Cabinet test3 = Cabinet(test2);
    assert(test3.get_material()==test2.get_material());
    assert(test3.get_position().get_x()==test2.get_position().get_x());
    assert(test3.get_position().get_y()==test2.get_position().get_y());
    assert(test3.get_position().get_z()==test2.get_position().get_z());

    assert(test3.get_size().get_x()==test2.get_size().get_x());
    assert(test3.get_size().get_y()==test2.get_size().get_y());
    assert(test3.get_size().get_z()==test2.get_size().get_z());


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
    assert(appliance.get_name()=="default");
    assert(appliance.get_state()== false);

    assert(appliance.get_position().get_x()==0);
    assert(appliance.get_position().get_y()==0);
    assert(appliance.get_position().get_z()==0);

    assert(appliance.get_size().get_x()==1);
    assert(appliance.get_size().get_y()==1);
    assert(appliance.get_size().get_z()==1);

    appliance.set_name("Fridge");
    appliance.changeState();
    appliance.set_position( Vector3(1, 2, 3));
    appliance.set_size( Vector3(4, 5, 6));
    appliance.set_state(true);

    assert(appliance.get_name() == "Fridge");
    assert(appliance.get_state() == true);

    assert(appliance.get_position().get_x()==1);
    assert(appliance.get_position().get_y()==2);
    assert(appliance.get_position().get_z()==3);

    assert(appliance.get_size().get_x()==4);
    assert(appliance.get_size().get_y()==5);
    assert(appliance.get_size().get_z()==6);

    Appliance appliance2 = Appliance(
            Vector3(1, 2, 3),
            Vector3(4, 5, 6),
            "Fridge",
            true);

    assert(appliance2.get_name() == "Fridge");
    assert(appliance2.get_state() == true);

    assert(appliance2.get_position().get_x()==1);
    assert(appliance2.get_position().get_y()==2);
    assert(appliance2.get_position().get_z()==3);

    assert(appliance2.get_size().get_x()==4);
    assert(appliance2.get_size().get_y()==5);
    assert(appliance2.get_size().get_z()==6);

    Appliance appliance3 = Appliance(appliance2);

    assert(appliance3.get_name()==appliance2.get_name());
    assert(appliance3.get_state()==appliance2.get_state());
    assert(appliance3.get_position().get_x()==appliance2.get_position().get_x());
    assert(appliance3.get_position().get_y()==appliance2.get_position().get_y());
    assert(appliance3.get_position().get_z()==appliance2.get_position().get_z());

    assert(appliance3.get_size().get_x()==appliance2.get_size().get_x());
    assert(appliance3.get_size().get_y()==appliance2.get_size().get_y());
    assert(appliance3.get_size().get_z()==appliance2.get_size().get_z());

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

    Plan plan = Plan();

    plan.addEntity(one);
    plan.addEntity(three);
    plan.addEntity(applianceThree);

    assert(plan.get_size().get_x()==1);
    assert(plan.get_size().get_y()==1);
    assert(plan.get_size().get_z()==1);
    assert(plan.get_entities().size() == 3);

    plan.set_size(Vector3(0.5,0.5,0.5));

    assert(plan.get_size().get_x()==0.5);
    assert(plan.get_size().get_y()==0.5);
    assert(plan.get_size().get_z()==0.5);

    Plan plan2 = Plan(Vector3(5,5,5));

    plan2.set_entities(plan.get_entities());

    assert(plan2.get_entities().size()==3);

    assert(plan.check() == false);
    assert(plan2.check() == true);

    std::cout<<"All testes has completed successfully"<<std::endl;
    return 0;
}
