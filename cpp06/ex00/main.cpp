#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac <= 1 || ac > 2)
	{
		std::cout << "error: Invalid parameters, must be 1" << std::endl;
		return (0);
	}
	std::string line = av[1];
	if (line.length() == 0)
	{
		std::cout << "error: Invalid parameters" << std::endl;
		return (0);
	}
	ScalarConverter converter;
	converter.convert(av[1]);
	return 0;
}