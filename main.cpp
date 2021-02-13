#include <iostream>
#include <fstream>
#include "headers\Particle.hpp"
#include "headers\Ground.hpp"
#include "headers\external\json.hpp"
#include <SFML\Graphics.hpp>
using namespace std;
using json = nlohmann::json;

int main() {
    Vector F = Vector(0.0, -0.007);

    Particle p = Particle(Vector(0.3, 0.6), Vector(0.02, 0.0), 0.02);
    Ground g = Ground("Test.json");

    sf::RenderWindow window(sf::VideoMode(800, 800), "RBD");
    window.setFramerateLimit(60);

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