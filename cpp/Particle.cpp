#include "..\headers\Particle.hpp"

Particle::Particle() {
    pos = Vector(0.0, 0.0);
    vel = Vector(0.06, 0.00);
    acc = Vector(0.0, 0.0);
    radius = 0.1f;
    mass = 1;
}
Particle::Particle(float x, float y, float radius_) {
    pos = Vector(x, y);
    vel = Vector(0.008, 0.0);
    acc = Vector(0.0, 0.0);
    radius = radius_;
    mass = 1.0;
}
Vector Particle::groundCollision(Ground& g) {
    for(int i = 0; i < g.getEdges().size()-1; i++) {
        float A = (g.getEdges().at(i).getY() - pos.getY())/g.getNormals().at(i).getY() - (g.getEdges().at(i).getX() - pos.getX())/g.getNormals().at(i).getX();
        float B = (g.getEdges().at(i+1).getX() - g.getEdges().at(i).getX())/g.getNormals().at(i).getX() - (g.getEdges().at(i+1).getY() - g.getEdges().at(i).getY())/g.getNormals().at(i).getY();
        float t = A/B;
        if(t <= 1 && t >= 0) {
            Vector r = (g.getEdges().at(i+1) - g.getEdges().at(i))*t + g.getEdges().at(i);
            Vector g = r - pos;
            float d = g.length() - radius;
            //if d <= radius --> collision --> calculate new force
        }
    }
    return Vector(2, 4);
}
void Particle::move(Vector& F, Ground& g) {

    groundCollision(g);

    pos = pos + vel*0.1 + F*(0.1*0.1/(2*mass));
    vel = vel + (F*(1/mass) + acc)*(0.1/2);
    acc = F*(1/mass);
}
void Particle::draw(sf::RenderWindow& win) {
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setOrigin(radius * win.getSize().y, radius * win.getSize().y);
    circle.setPosition(sf::Vector2f(pos.getX() * win.getSize().x, win.getSize().y * (1-pos.getY())));
    circle.setRadius(radius * win.getSize().y);
    win.draw(circle);
}
std::ostream& operator<<(std::ostream& os, const Particle& p) {
    os << "Pos: " << p.pos << ", Vel: " << p.vel << ", Acc: " << p.acc;
    return os;
}