#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
class Vector {
    private:
        float x, y;
    public:
        Vector();
        Vector(float, float);

        float getX();
        float getY();

        void setX(float);
        void setY(float);
};
#endif