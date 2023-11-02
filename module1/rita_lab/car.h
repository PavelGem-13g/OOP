#include <iostream>

class Car {
public:
    Car() = default;
    Car(const Car& in) = default;

    Car(float speed, float acceleration, float angle, float angular_acceleration, float y, float x);

    void setSpeed(float speed);
    float getSpeed() const;
    void setAcceleration(float acceleration);
    float getAcceleration() const;
    void setAngle(float angle);
    float getAngle() const;
    void setAngular_acceleration(float angular_acceleration);
    float getAngular_acceleration() const;
    void setY(float y);
    float getY() const;
    void setX(float X);
    float getX() const;

private:
    float m_x = 0.0;
    float m_y = 0.0;
    float m_speed = 0.0;
    float m_acceleration = 0.0;
    float m_angular_acceleration = 0.0;
    float m_angle = 0.0;
};

