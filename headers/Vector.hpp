#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include <iostream>
class Vector {
    private:
        float x, y;
    public:
        Vector();
        Vector(float, float);

        Vector operator+(Vector&);
        Vector operator*(float);
        friend std::ostream& operator<<(std::ostream&, const Vector&);

        float getX();
        float getY();

        void setX(float);
        void setY(float);
};
#endif