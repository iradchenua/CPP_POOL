#include "Pony.hpp"

void	ponyOnTheStack(void)
{
	Pony pony = Pony("red", "Adolf", "Stack");
}

Pony	*ponyOnTheHeap(void)
{
	Pony *pony = new Pony("black", "Josif", "Heap");
	return (pony);
}

int 	main(void)
{
	Pony *Josif;

	std::cout << "ponyOnTheStack call" << std::endl;
	ponyOnTheStack();
	std::cout << "ponyOnTheStack end" << std::endl;
	std::cout << "ponyOnTheHeap call" << std::endl;
	Josif = ponyOnTheHeap();
	std::cout << "ponyOnTheHeap end" << std::endl;
	std::cout << "How you can see second pony" \
	<< " lives in this moment, but the function ponyOnTheHeap " \
	<< "was end" << std::endl;
	delete Josif;
	return (0);
}