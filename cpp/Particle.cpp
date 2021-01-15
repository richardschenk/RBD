#include "..\headers\Particle.hpp"

Particle::Particle() {
    pos = Vector(0.0, 0.0);
    vel = Vector(0.3, 0.0);
    acc = Vector(0.0, 0.0);
    radius = 0.1f;
    mass = 1;
}
Particle::Particle(float x, float y, float radius_) {
    pos = Vector(x, y);
    vel = Vector(0.3, 0.0);
    acc = Vector(0.0, 0.0);
    radius = radius_;
}
void Particle::move(float F) {
    pos = (vel*0.1) + pos;
}
std::ostream& operator<<(std::ostream& os, const Particle& p) {
    os << "Pos: " << p.pos << ", Vel" << p.vel;
    return os;
}