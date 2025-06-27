#include "Graph.hpp"
#include <iostream>

int main() {
    Graph graph(Vector2(5, 5));


    graph.addPoint(Vector2(0,0));
    graph.addPoint(Vector2(2,2));
    graph.addPoint(Vector2(4,2));
    graph.addPoint(Vector2(2,4));

    try { graph.addPoint(Vector2(6,6)); } catch (std::exception& e) { std::cout << e.what() << std::endl; }


    std::cout << "\nGraph contents:\n";
    graph.draw();

    return 0;
}