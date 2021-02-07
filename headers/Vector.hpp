#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include <iostream>
#include <cmath>
class Vector {
    private:
        float x, y;
    public:
        Vector();
        Vector(float, float);

        Vector operator+(const Vector&);
        Vector operator-(const Vector&);
        Vector operator*(float);
        friend std::ostream& operator<<(std::ostream&, const Vector&);

        float getX() const;
        float getY() const;
        float length();
        void normalize();

        void setX(float);
        void setY(float);
};
#endif