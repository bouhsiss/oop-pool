#include "Graph.hpp"
#include <iostream>
#include <iomanip>

Graph::Graph(const Vector2& size) : _size(size) {}

void Graph::addPoint(const Vector2& point) {
    if ( point.getX() > _size.getX() || point.getY() > _size.getY())
        throw std::runtime_error("Point out of bounds");
    _points.push_back(point);
}

void Graph::draw() const {
    int w = _size.getX();
    int h = _size.getY();

    for (int y = h; y >= 0; --y) {
        std::cout << " " << y << " ";
        for (int x = 0; x <= w; ++x) {
            bool mark = false;
            std::vector<Vector2>::const_iterator it;
            for (it = _points.begin(); it != _points.end(); ++it) {
                if (it->getX() == x && it->getY() == y) {
                    mark = true;
                    break;
                }
            }
            std::cout << " " << (mark ? 'X' : '.' ) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "   ";
    for (int x = 0; x <= w; ++x) {
        std::cout << " " << x << " ";
    }
    std::cout << std::endl;
}