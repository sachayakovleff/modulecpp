#include "Span.hpp"

int main(void)
{
	Span s1(5);
	std::cout << "trying with 5 values" << std::endl;
	try
	{
		s1.addNumber(1);
		s1.addNumber(8);
		s1.addNumber(42);
		s1.addNumber(4);
		s1.addNumber(41);
		std::cout << "max span: " << s1.longestSpan() << std::endl;
		std::cout << "min span: " << s1.shortestSpan() << std::endl;
	//s1.addNumber(52);
	}
	catch (Span::ImpossibleSpanCalculException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (Span::VectorMaxValueException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "trying for 10000 values" << std::endl;
	Span s2(10000);
	try
	{
		srand(50);
		for (int i = 0; i < 10000; i++)
		{
			s2.addNumber(rand());
		}
		std::cout << "max span: " << s2.longestSpan() << std::endl;
		std::cout << "min span: " << s2.shortestSpan() << std::endl;
	}
	catch (Span::ImpossibleSpanCalculException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (Span::VectorMaxValueException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "Now it's better" << std::endl;
	Span s3(20000);
	try
	{
		s3.addNumber(static_cast <unsigned int>(20000));
		std::cout << "max span: " << s3.longestSpan() << std::endl;
		std::cout << "min span: " << s3.shortestSpan() << std::endl;
	}
	catch (Span::ImpossibleSpanCalculException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (Span::VectorMaxValueException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}