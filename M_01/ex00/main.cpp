#include "Worker.hpp"
#include "Shovel.hpp"

int main()
{
	Position p(1, 2, 3);
	Statistic s(10, 500);

	std::cout << "=== Create workers ===\n";
	Worker w1(p, s);
	Worker w2(p, s);

	std::cout << "\n=== Create shovel (independent object) ===\n";
	Shovel shovel;

	std::cout << "\n=== Give shovel to w1 and use it ===\n";
	w1.giveShovel(&shovel);
	w1.useShovel();

	std::cout << "\n=== Give SAME shovel to w2 (should remove from w1) ===\n";
	w2.giveShovel(&shovel);

	std::cout << "\n=== Try using shovel from w1 (should fail) ===\n";
	w1.useShovel();

	std::cout << "\n=== Use shovel from w2 (should work) ===\n";
	w2.useShovel();

	std::cout << "\n=== w2 gives shovel away, then tries using it ===\n";
	w2.takeShovel();
	w2.useShovel();

	std::cout << "\n=== End of program (workers destroyed, shovel should still be destroyed once at end) ===\n";
	return 0;
}