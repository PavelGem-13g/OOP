#include <iostream>

class Point{
    int x;
    int y;

public:
    Point();
    Point(int x, int y);

    int getX();
    int getY();

    int getDistance(Point other);
};

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

int Point::getDistance(Point other) {
    Point diff = Point(this->getX()-other.getX(), this->getY()-other.getY());
    return int(sqrt(pow(diff.getX(), 2)+ pow(diff.getY(), 2)));
}

class RectAngle{
public:
    Point points[4];
    RectAngle(Point one, Point two, Point three, Point four);
    int getType();
};

int RectAngle::getType() {
    for (int i = 0; i < 4; ++i) {

    }
    return 0;
}

int main() {

    RectAngle rectAngle = RectAngle(Point(0, 0), Point(1, 1), Point(1, 4), Point(0, 4));

    return 0;
}
