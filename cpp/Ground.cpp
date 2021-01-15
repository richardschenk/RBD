#include "..\headers\Ground.hpp"

void Ground::addEdge(float x, float y) {
    edges.push_back(Vector(x, y));
}