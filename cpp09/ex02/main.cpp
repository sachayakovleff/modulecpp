#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "syntax: ./PmergeMe <integer> <integer> ..." << std::endl;
		return (1);
	}
	PmergeMe merge;
	merge.calculate(ac, av);
}