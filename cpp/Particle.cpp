#include "..\headers\Particle.hpp"

Particle::Particle() {
    pos = Vector(0.0, 0.0);
    vel = Vector(0.0, 0.0);
    acc = Vector(0.0, 0.0);
    radius = 0.1f;
    mass = 1;
}
Particle::Particle(float x, float y, float radius_) {
    pos = Vector(x, y);
    vel = Vector(0.003, 0.0);
    acc = Vector(0.0, 0.0);
    radius = radius_;
    mass = 1.0;
}
void Particle::move(Vector& F) {
    pos = pos + vel*0.1 + F*(0.1*0.1/(2*mass));
    vel = vel + (F*(1/mass) + acc)*(0.1/2);
    acc = F*(1/mass);
}
void Particle::draw(sf::RenderWindow& win) {
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setPosition(sf::Vector2f(pos.getX() * win.getSize().x, win.getSize().y * (1-pos.getY())));
    circle.setRadius(radius * win.getSize().y);
    win.draw(circle);
}
std::ostream& operator<<(std::ostream& os, const Particle& p) {
    os << "Pos: " << p.pos << ", Vel: " << p.vel << ", Acc: " << p.acc;
    return os;
}