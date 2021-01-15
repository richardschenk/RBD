#include "..\headers\Particle.hpp"

Particle::Particle() {
    pos = Vector(0.0, 0.0);
    vel = Vector(0.0, 0.0);
    radius = 0.1f;
    mass = 1;
}
Particle::Particle(float x, float y, float radius_) {
    pos = Vector(x, y);
    radius = radius_;
}