#include "car.h"


Car::Car(float speed, float acceleration, float angle, float angular_acceleration, float y, float x)
{
    this->m_speed = speed;
    this->m_acceleration = acceleration;
    this->m_angle = angle;
    this->m_angular_acceleration = angular_acceleration;
    this->m_y = y;
    this->m_x = x;
}

void Car::setSpeed(float speed) {
    if ((speed <= 1.0f*(-100)) || (speed >= 1.0f * 100)) {
        std::cout << "Speed can't be <(-100) or >100" << std::endl;
        return;
    }
    m_speed = speed;
}

float Car::getSpeed() const {
    return m_speed;
}



float Car::getAcceleration() const {
    return m_acceleration;
}
void Car::setAngle(float angle) {
    m_angle = angle;
}
float Car::getAngle() const {
    return m_angle;
}
void Car::setAngular_acceleration(float angular_acceleration)
{
    m_angular_acceleration = angular_acceleration;
}
float Car::getAngular_acceleration() const
{
    return m_angular_acceleration;
}
void Car::setY(float y) {
    m_y = y;
}
float Car::getY() const {
    return m_y;
}
void Car::setX(float x) {
    m_x = x;
}
float Car::getX() const {
    return m_x;
}

void Car::setAcceleration(float acceleration) {

}
