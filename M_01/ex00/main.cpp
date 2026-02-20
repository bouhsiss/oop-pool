#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

int main()
{
    Position p(1, 2, 3);
    Statistic s(10, 500);

    std::cout << "=== Create workers ===\n";
    Worker w1(p, s);
    Worker w2(p, s);

    std::cout << "\n=== Create tools (independent objects) ===\n";
    Shovel shovel;
    Hammer hammer;

    std::cout << "\n=== Give shovel + hammer to w1 ===\n";
    w1.addTool(&shovel);
    w1.addTool(&hammer);

    std::cout << "\n=== w1 uses all tools ===\n";
    w1.useTools();

    std::cout << "\n=== Give SAME shovel to w2 (should remove from w1) ===\n";
    w2.addTool(&shovel);

    std::cout << "\n=== w1 uses all tools (should only have hammer now) ===\n";
    w1.useTools();

    std::cout << "\n=== w2 uses all tools (should have shovel) ===\n";
    w2.useTools();

    std::cout << "\n=== Remove hammer from w1 and test ===\n";
    w1.removeTool(&hammer);
    w1.useTools();

    std::cout << "\n=== End (tools destroyed once, workers destroyed, Tool base destructors should run too) ===\n";
    return 0;
}