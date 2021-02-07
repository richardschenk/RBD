#ifndef _PARTICLE_HPP_
#define _PARTICLE_HPP_
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
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
        void move(Vector&);
        void draw(sf::RenderWindow&);

        friend std::ostream& operator<<(std::ostream&, const Particle&);
};
#endif