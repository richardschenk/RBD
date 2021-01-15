#include "..\headers\Vector.hpp"

Vector::Vector() {
    x = 0;
    y = 0;
}
Vector::Vector(float x_, float y_) {
    x = x_;
    y = y_;
}
float Vector::getX() {
    return x;
}
float Vector::getY() {
    return y;
}
void Vector::setX(float x_) {
    x = x_;
}
void Vector::setY(float y_) {
    y = y_;
}