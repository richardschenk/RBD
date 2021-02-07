#include <iostream>

#include "headers\Particle.hpp"
#include "headers\Ground.hpp"
#include <SFML\Graphics.hpp>
using namespace std;

int main() {
    Vector F = Vector(0.0, -0.0001);
    Particle p = Particle(0.1, 0.5, 0.025);
    Ground g;


    sf::RenderWindow window(sf::VideoMode(800, 800), "RBD");
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        p.move(F, g);

        window.clear();
        g.draw(window);
        p.draw(window);
        window.display();
    }
}