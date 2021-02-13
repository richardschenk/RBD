#pragma once
#include "Vector.hpp"
#include <cmath>
#include "Ground.hpp"
#include <SFML/Graphics.hpp>
class Particle {
    private:
        int hitCount;
        float radius;
        float mass;
        Vector pos;
        Vector vel;
        Vector acc;

        Vector groundCollision(Ground&, Vector&);

    public:
        Particle();
        Particle(const Vector&, const Vector&, float);
        void move(Vector&, Ground&);
        void draw(sf::RenderWindow&);

        friend std::ostream& operator<<(std::ostream&, const Particle&);
};