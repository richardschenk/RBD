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
        if(v.getX() == 0) {
            v.setX(0.0000001);
        } else if(v.getY() == 0) {
            v.setY(0.0000001);
        }
        v.normalize();
        normals.push_back(v);
    }
}

void Ground::addEdge(float x, float y) {
    edges.push_back(Vector(x, y));
}
std::vector<Vector>& Ground::getEdges() {
    return edges;
}
std::vector<Vector>& Ground::getNormals() {
    return normals;
}
void Ground::draw(sf::RenderWindow& win) {

    sf::VertexArray line(sf::LineStrip, edges.size());

    for(int i = 0; i < edges.size(); i++) {
        line[i].position = sf::Vector2f(win.getSize().x * edges[i].getX(), win.getSize().y * (1 - edges[i].getY()));
    }

    win.draw(line);

}