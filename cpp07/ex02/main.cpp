#include "array.hpp"

int main(void)
{
	Array <int>array(5);
	array.setValue(4, 4);
	array.setValue(3, 1);
	try
	{
		array.getValue(8000);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << array << std::endl;
}