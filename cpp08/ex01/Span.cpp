#include "Span.hpp"
#include <climits>

Span::Span()
{
	this->sizemax = 0;
	this->currentsize = 0;
}

Span::Span(unsigned int size)
{
	this->sizemax = size;
	this->currentsize = 0;
}

Span::Span(Span& copy)
{
	*this = copy;
	this->sizemax = copy.sizemax;
	this->numbers = copy.numbers;
	this->currentsize = copy.currentsize;
}

Span& Span::operator=(Span& copy)
{
	*this = copy;
	this->sizemax = copy.sizemax;
	this->numbers = copy.numbers;
	this->currentsize = copy.currentsize;
	return (*this);
}

std::vector<int> &Span::getNumbers()
{
	return this->numbers;
}

void Span::addNumber(int value)
{
	if (this->currentsize < this->sizemax)
	{
		this->numbers.push_back(value);
		this->currentsize += 1;
	}
	else
	{
		throw (VectorMaxValueException());
	}
}

void	Span::addNumber(unsigned int size)
{
	if (size + this->currentsize > this->sizemax)
		throw(VectorMaxValueException());
	srand(time(0));
	for (unsigned int i = 0; i < size; i++)
	{
		int rand_int = INT_MAX;
		while (rand_int > 1000000 || rand_int < 0 || this->numbers.end() != std::find(this->numbers.begin(), this->numbers.end(), rand_int))
		{
			rand_int = rand(); ;
		}
		addNumber(rand_int);
	}

}

template <typename T>
typename T::iterator getMaxContainerValue(T container, int currentsize)
{
	(void)currentsize;
	return std::max_element(container.begin(), container.end());
}

template <typename T>
typename T::iterator getMinContainerValue(T container, int currentsize)
{
	return std::min_element(container.begin(), container.begin() + currentsize);
}

int Span::longestSpan() const
{
	if (this->currentsize <= 1)
		throw (ImpossibleSpanCalculException());
	int result = *getMaxContainerValue(this->numbers, this->currentsize) - *getMinContainerValue(this->numbers, this->currentsize);
	return result;
}

int Span::shortestSpan()
{
	if (this->currentsize <= 1)
		throw (ImpossibleSpanCalculException());

	int				res = 0;
	int				i = 0;

	std::sort(this->numbers.begin(), this->numbers.end());
	res = ::abs(this->numbers[1] - this->numbers[0]);
	while (i < (int)this->numbers.size())
	{
		if (res > ::abs(this->numbers[i] - this->numbers[i + 1]))
			res = ::abs(this->numbers[i] - this->numbers[i + 1]);
		i++;
	}
	return (res);
}

