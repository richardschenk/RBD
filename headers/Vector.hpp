#pragma once
#include <iostream>
#include <cmath>
class Vector {
    private:
        float x, y;
    public:
        //Constructors
        Vector();
        Vector(float, float);

        //Operators
        Vector operator+(const Vector&);
        Vector operator-(const Vector&);
        void operator+=(const Vector&);
        void operator*=(float);
        void operator-=(const Vector&);
        float operator*(const Vector&);
        friend std::ostream& operator<<(std::ostream&, const Vector&);
        friend Vector operator*(float, const Vector&);
        friend Vector operator*(const Vector&, float);

        //Getter & Setter
        float getX() const;
        float getY() const;
        void setX(float);
        void setY(float);

        //Other functions
        float length();
        void normalize();
};