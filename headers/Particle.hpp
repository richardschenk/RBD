#ifndef _PARTICLE_HPP_
#define _PARTICLE_HPP_
#include "Vector.hpp"
class Particle {
    private:
        float radius;
        float mass;
        Vector pos;
        Vector vel;
        Vector acc;

    public:
        Particle();
        Particle(float, float, float);
        void move(float)
};
#endif