#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include "Vector2.hpp"

class Graph {
    private:
        Vector2 _size;
        std::vector<Vector2> _points;
    public:
        Graph(const Vector2& size);

        void addPoint(const Vector2& point);
        void draw() const;
};

#endif