#include "..\headers\Vector.hpp"
#include <iostream>

//Constructors
Vector::Vector() {
    x = 0;
    y = 0;
}
Vector::Vector(float x_, float y_) {
    x = x_;
    y = y_;
}

//Operator
Vector Vector::operator+(const Vector& vec) {
    return Vector(x + vec.x, y + vec.y);
}
Vector Vector::operator-(const Vector& vec) {
    return Vector(x - vec.x, y - vec.y);
}
float Vector::operator*(const Vector& vec) {
    float X = vec.getX() * x;
    float Y = vec.getY() * y;
    return X+Y;
}
Vector operator*(float f, const Vector& vec) {
    return Vector(f*vec.getX(), f*vec.getY());
}
Vector operator*(const Vector& vec, float f) {
    return Vector(f*vec.getX(), f*vec.getY());
}
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[" << vec.x << "|" << vec.y << "]";
    return os;
}
void Vector::operator+=(const Vector& vec) {
    x += vec.x;
    y += vec.y;
}
void Vector::operator-=(const Vector& vec) {
    x -= vec.x;
    y -= vec.y;
}
void Vector::operator*=(float f) {
    x *= f;
    y *= f;
}

//Getter & Setter
float Vector::getX() const {
    return x;
}
float Vector::getY() const {
    return y;
}
void Vector::setX(float x_) {
    x = x_;
}
void Vector::setY(float y_) {
    y = y_;
}

//Other functions
float Vector::length() {
    return sqrt(x*x + y*y);
}
void Vector::normalize() {
    float l = length();
    x /= l;
    y /= l;
}