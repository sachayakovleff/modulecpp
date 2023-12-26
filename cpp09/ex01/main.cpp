#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Invalid argument: must be valid integer and operators" << std::endl;
		std::cout << "Example: ./RPN \"1 4 * 2 + 4 - 1 +\"" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.calculate(av[1]);
}