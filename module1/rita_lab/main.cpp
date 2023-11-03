#include <assert.h>
#include "car.h"
using namespace std;

int main()
{
    // Проверка на правильные значения по умолчанию
    Car defCar;
    assert(defCar.getX() == 0);
    assert(defCar.getY() == 0);
    assert(defCar.getAngle() == 0);
    assert(defCar.getAcceleration() == 0);
    assert(defCar.getSpeed() == 0);

    // Проверка работы модификаторов и селекторов
    defCar.setX(5.0);
    defCar.setY(5.0);
    defCar.setSpeed(1.0);
    defCar.setAcceleration(1.0);
    defCar.setAngle(30.0);
    assert(defCar.getSpeed() == 1.0);
    assert(defCar.getAcceleration() == 1.0);
    assert(defCar.getAngle() == 30.0);
    assert(defCar.getX() == 5.0);
    assert(defCar.getY() == 5.0);


    // Проверка копирования
    Car copiedCar(defCar);
    assert(copiedCar.getSpeed() == 1.0);
    assert(copiedCar.getAcceleration() == 1.0);
    assert(copiedCar.getAngle() == 30.0);
    assert(copiedCar.getX() == 5.0);
    assert(copiedCar.getY() == 5.0);

    // Проверка конструктора инициализации
    Car initiedCar(100.0, 50.0, 0.0, 0.0, 0.0, 0.0);
    assert(initiedCar.getSpeed() == 100);
    assert(initiedCar.getAcceleration() == 50.0);
    assert(initiedCar.getAngle() == 0.0);
    assert(initiedCar.getX() == 0.0);
    assert(initiedCar.getY() == 0.0);

    cout << "All tests complete";
    return 0;
}
