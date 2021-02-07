#ifndef _PARTICLE_HPP_
#define _PARTICLE_HPP_
#include "Vector.hpp"
#include "Ground.hpp"
#include <SFML/Graphics.hpp>
class Particle {
    private:
        float radius;
        float mass;
        Vector pos;
        Vector vel;
        Vector acc;

        Vector groundCollision(Ground&);

    public:
        Particle();
        Particle(float, float, float);
        void move(Vector&, Ground&);
        void draw(sf::RenderWindow&);

        friend std::ostream& operator<<(std::ostream&, const Particle&);
};
#endif