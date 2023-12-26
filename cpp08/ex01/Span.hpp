#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	unsigned int	sizemax;
	unsigned int	currentsize;
	std::vector<int> numbers;
public:
	Span();
	Span(unsigned int size);
	Span(Span& copy);
	Span& operator=(Span& copy);
	std::vector<int> &getNumbers();
	void addNumber(int value);
	int shortestSpan();
	int longestSpan() const;	
	void addNumber(unsigned int size);
	class VectorMaxValueException : std::exception
	{
	public:
		char *what() {
			std::cout << "Vector already reached max value" << std::endl;
			return (NULL);
		};
	};
	class ImpossibleSpanCalculException : std::exception
	{
	public:
		char *what() {
			std::cout << "Cannot calculate span between values" << std::endl;
			return (NULL);
		};
	};
};