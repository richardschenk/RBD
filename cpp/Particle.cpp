#include "..\headers\Particle.hpp"

Particle::Particle() {
    pos = Vector(0.0, 0.0);
    vel = Vector(0.0, 0.00);
    acc = Vector(0.0, 0.0);
    radius = 0.1f;
    mass = 1;
    hitCount = 0;
}
Particle::Particle(const Vector& pos_,const Vector& vel_, float radius_) {
    pos = pos_;
    vel = vel_;
    acc = Vector(0.0, 0.0);
    radius = radius_;
    mass = 1.0;
    hitCount = 0;
}
Vector Particle::groundCollision(Ground& g, Vector& F) {
    Vector force = Vector(0, 0);
    for(int i = 0; i < g.getEdges().size()-1; i++) {
        float A = (g.getEdges().at(i).getY() - pos.getY())/g.getNormals().at(i).getY() - (g.getEdges().at(i).getX() - pos.getX())/g.getNormals().at(i).getX();
        float B = (g.getEdges().at(i+1).getX() - g.getEdges().at(i).getX())/g.getNormals().at(i).getX() - (g.getEdges().at(i+1).getY() - g.getEdges().at(i).getY())/g.getNormals().at(i).getY();
        float t = A/B;
        if(t <= 1 && t >= 0) {
            Vector r = (g.getEdges().at(i+1) - g.getEdges().at(i))*t + g.getEdges().at(i);
            Vector diff = r - pos;
            if(diff.length() <= radius && vel*g.getNormals().at(i) <= 0) { //v' = v + 2(v*n)*n
                if(fabs(vel.getX()) <= 0.001) {
                    vel.setX(0);
                }
                if(fabs(vel.getY()) <= 0.001) {
                    vel.setY(0);
                }
                float s;
                if(vel.getX() <= 0) {
                    s = +1;
                } else {
                    s = -1;
                }
                float tangential = s * 0.02 * (mass/0.1) * fabs(vel*g.getTangentials().at(i));
                float normal = 0.6 * 2 * (mass/0.1) * fabs((vel*g.getNormals().at(i)));
                force += (g.getNormals().at(i)*normal);
                force += (g.getTangentials().at(i)*tangential);
                force -= F;
            }
        }
    }
    return force;
}
void Particle::move(Vector& F, Ground& g) {

    Vector F2 = groundCollision(g, F);
    Vector totalF = F + F2;

    pos += 0.1*vel + (0.1*0.1/(2*mass))*totalF;
    vel += (0.1/2)*((1/mass)*totalF + acc);
    acc = (1/mass)*totalF;
    
}
void Particle::draw(sf::RenderWindow& win) {
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setOrigin(radius * win.getSize().x, radius * win.getSize().y);
    circle.setPosition(sf::Vector2f(pos.getX() * win.getSize().x, win.getSize().y * (1-pos.getY())));
    circle.setRadius(radius * win.getSize().y);
    win.draw(circle);
}
std::ostream& operator<<(std::ostream& os, const Particle& p) {
    os << "Pos: " << p.pos << ", Vel: " << p.vel << ", Acc: " << p.acc;
    return os;
}