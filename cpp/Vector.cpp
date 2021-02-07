#include "..\headers\Vector.hpp"
#include <iostream>

Vector::Vector() {
    x = 0;
    y = 0;
}
Vector::Vector(float x_, float y_) {
    x = x_;
    y = y_;
}

Vector Vector::operator+(const Vector& vec) {
    return Vector(x + vec.x, y + vec.y);
}
Vector Vector::operator-(const Vector& vec) {
    return Vector(x - vec.x, y - vec.y);
}
Vector Vector::operator*(float k) {
    return Vector(k*x, k*y);
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
float Vector::length() {
    return sqrt(x*x + y*y);
}
void Vector::normalize() {
    float l = length();
    x /= l;
    y /= l;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[" << vec.x << "|" << vec.y << "]";
    return os;
}