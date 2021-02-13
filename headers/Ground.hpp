#pragma once
#include <vector>
#include "Vector.hpp"
#include "external\json.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
class Ground {
    private:
        std::vector<Vector> edges;
        std::vector<Vector> normals;
        std::vector<Vector> tangentials;
        void calcNormals();
        void calcTangentials();
    public:
        void addEdge(float, float);
        void draw(sf::RenderWindow&);
        void saveGround(const std::string&);
        void loadGround(const std::string&);
        std::vector<Vector>& getEdges();
        std::vector<Vector>& getNormals();
        std::vector<Vector>& getTangentials();

        Ground(const std::string&);
};