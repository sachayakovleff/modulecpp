#include "easyfind.hpp"
#include <list>
#include <deque>


int main(void)
{
	std::cout << "trying deque: " << std::endl;
	try
	{
		std::deque<int> d1(10000);
		for (int i = 0; i < 10000; i++)
			d1.push_back(i);
		std::cout << "value : " << *easyfind(d1, 4242) << std::endl;
		std::cout << "value : " << *easyfind(d1, 9999) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
	std::cout << "trying vectors: " << std::endl;
	try
	{
		std::vector<int> v1;
		for (int i = 0; i < 10000; i++)
			v1.push_back(i);
		std::cout << "value : " << *easyfind(v1, 4242) << std::endl;
		std::cout << "value : " << *easyfind(v1, 100000) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
	return (0);
}