
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate()
{
	int i = rand() % 3;
	std::cout << "type chosen: " << i << std::endl;
	switch (i)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void	identify(Base *b)
{
	if (dynamic_cast <A*>(b))
		std::cout << "Base is type A" << std::endl;
	if (dynamic_cast <B*>(b))
		std::cout << "Base is type B" << std::endl;
	if (dynamic_cast <C*>(b))
		std::cout << "Base is type C" << std::endl;

}

int main(void)
{
	Base* b;
	srand(time(NULL));
	b = generate();
	if (b == NULL)
	{
		std::cout << "memory error, couldn't create Base type" << std::endl;
		return (1);
	}
	else
	{
		identify(b);
		return (0);
	}
}