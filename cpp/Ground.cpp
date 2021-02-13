#include "..\headers\Ground.hpp"
using json = nlohmann::json;

Ground::Ground(const std::string& path) {
    loadGround(path);

    calcNormals();
    calcTangentials();
}

void Ground::calcNormals() {
    for(int i = 0; i < edges.size()-1; i++) {
        Vector v = Vector( edges[i].getY() - edges[i+1].getY(), edges[i+1].getX() - edges[i].getX());
        if(v.getX() == 0) {
            v.setX(0.0000001);
        } else if(v.getY() == 0) {
            v.setY(0.0000001);
        }
        v.normalize();
        normals.push_back(v);
    }
}
void Ground::calcTangentials() {
    for(int i = 0; i < edges.size()-1; i++) {
        Vector v = Vector( edges[i+1].getX() - edges[i].getX(), edges[i+1].getY() - edges[i].getY());
        v.normalize();
        tangentials.push_back(v);
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
std::vector<Vector>& Ground::getTangentials() {
    return tangentials;
}
void Ground::draw(sf::RenderWindow& win) {

    sf::VertexArray line(sf::LineStrip, edges.size());

    for(int i = 0; i < edges.size(); i++) {
        line[i].position = sf::Vector2f(win.getSize().x * edges[i].getX(), win.getSize().y * (1 - edges[i].getY()));
    }

    win.draw(line);

}

void Ground::saveGround(const std::string& path) {
    json j;
    for(int i = 0; i < edges.size(); i++) {
        j["points"][std::to_string(i)] = { edges[i].getX(), edges[i].getY()};
    }
    std::fstream f;
    f.open(path, std::ios::out);
    f << j;
    f.close();
}
void Ground::loadGround(const std::string& path) {
    json j;
    std::fstream f;
    f.open(path, std::ios::in);
    f >> j;
    f.close();

    for(int i = 0; i < j["points"].size(); i++) {
        edges.push_back(Vector(j["points"][std::to_string(i)][0], j["points"][std::to_string(i)][1]));
    }
}