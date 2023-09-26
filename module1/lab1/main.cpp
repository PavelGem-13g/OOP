#include <iostream>
#include <cassert>

#include "Cabinet.h"
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
            "wood",
            Vector3(1, 2, 3),
            Vector3(4, 5, 6)
            );

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
            "wood",
            Vector3(),
            Vector3(1, 1, 1)
            );

    Cabinet two = Cabinet(
            "metal",
            Vector3(),
            Vector3(2, 2, 2)
            );

    Cabinet three = Cabinet(
            "plastic",
            Vector3(10, 10, 10),
            Vector3(1, 1,1)
            );

    Cabinet four = Cabinet(
            "plastic",
            Vector3(1.5, 0, 0),
            Vector3(0.1, 0.1, 0.1)
            );

    assert(one.isCollision(two)==1);
    assert(one.isCollision(three)==0);
    assert(one.isCollision(four)==1);

    std::cout<<"All testes has completed successfully"<<std::endl;

    return 0;
}
