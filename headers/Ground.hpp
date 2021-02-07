#ifndef _GROUND_HDD_
#define _GROUND_HDD_
#include <vector>
#include "..\headers\Vector.hpp"
#include <SFML/Graphics.hpp>
class Ground {
    private:
        std::vector<Vector> edges;
        std::vector<Vector> normals;
        void calcNormals();
    public:
        void addEdge(float, float);
        void draw(sf::RenderWindow&);
        std::vector<Vector>& getEdges();
        std::vector<Vector>& getNormals();

        Ground();
};
#endif