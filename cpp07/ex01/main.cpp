#include "iter.hpp"
#include <iostream>

static void print(int const &value)
{
	std::cout << value << std::endl;
}

int main(void)
{
	int values[5] = { 4, 2, 21, 42, 666 };
	iter(values, 5, print);
}