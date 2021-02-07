#include "..\headers\Ground.hpp"

Ground::Ground() {
    edges.push_back(Vector(0.0, 0.25));
    edges.push_back(Vector(0.25, 0.2));
    edges.push_back(Vector(0.4, 0.2));
    edges.push_back(Vector(0.6, 0.22));
    edges.push_back(Vector(1.0, 0.3));    

    calcNormals();
}

void Ground::calcNormals() {
    for(int i = 0; i < edges.size()-1; i++) {
        Vector v = Vector( edges[i+1].getY() - edges[i].getY(), edges[i].getX() - edges[i+1].getX());
        v.normalize();
        normals.push_back(v);
        std::cout << normals[i] << std::endl;
    }
}

void Ground::addEdge(float x, float y) {
    edges.push_back(Vector(x, y));
}

void Ground::draw(sf::RenderWindow& win) {

    sf::VertexArray line(sf::LineStrip, edges.size());

    for(int i = 0; i < edges.size(); i++) {
        line[i].position = sf::Vector2f(win.getSize().x * edges[i].getX(), win.getSize().y * (1 - edges[i].getY()));
    }

    win.draw(line);

}