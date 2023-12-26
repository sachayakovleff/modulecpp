#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN& copy)
{
	if (&copy != this)
		this->calculator = copy.calculator;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(RPN& copy)
{
	if (&copy != this)
		this->calculator = copy.calculator;
	return (*this);
}

void RPN::ft_substract(char c)
{
	if (c != '-')
		return;
	double value1 = this->calculator.top();					//get first and second last values to make the substraction
	this->calculator.pop();
	double value2 = this->calculator.top();
	this->calculator.pop();
	this->calculator.push(value2 - value1);					//push the result
}

void RPN::ft_add(char c)
{
	if (c != '+')
		return;
	double value1 = this->calculator.top();					//get first and second last values to make the addition
	this->calculator.pop();
	double value2 = this->calculator.top();
	this->calculator.pop();
	this->calculator.push(value2 + value1);					//push the result
}

void RPN::ft_mult(char c)
{
	if (c != '*')
		return;
	double value1 = this->calculator.top();					//get first and second last values to make the multiplication
	this->calculator.pop();
	double value2 = this->calculator.top();
	this->calculator.pop();
	this->calculator.push(value2 * value1);					//push the result
}

void RPN::ft_divide(char c)
{
	if (c != '/')
		return;
	double value1 = this->calculator.top();					//get first and second last values to make the division
	this->calculator.pop();
	double value2 = this->calculator.top();
	this->calculator.pop();
	this->calculator.push(value2 / value1);					//push the result
}

void RPN::ft_addvalue(char c)
{
	this->calculator.push(c - '0');
}

static void ft_printerr()
{
	std::cout << "Error: invalid argument" << std::endl;
}


void RPN::calculate(char* av)
{
	std::string numbers(av);
	
	for (long unsigned int i = 0; i < numbers.size(); i++)
	{
		char c = numbers[i];
		if (c == ' ')
			continue;
		if (c == '-')
		{
			if (this->calculator.size() < 2)
			{
				ft_printerr();
				return;
			}
			ft_substract(c);
			continue;
		}
		else if (c == '+')
		{
			if (this->calculator.size() < 2)
			{
				ft_printerr();
				return;
			}
			ft_add(c);
			continue;
		}
		else if (c == '*')
		{
			if (this->calculator.size() < 2)
			{
				ft_printerr();
				return;
			}
			ft_mult(c);
			continue;
		}
		else if (c == '/')
		{
			if (this->calculator.size() < 2)
			{
				ft_printerr();
				return;
			}
			if (this->calculator.top() == 0.0)
			{
				std::cout << "Error: can't divide by 0" << std::endl;
				return;
			}
			ft_divide(c);
			continue;
		}
		else
		{
			if (isdigit(c) == true)
			{
				ft_addvalue(c);
				continue;
			}
			else
			{
				ft_printerr();
				return;
			}
		}
	}
	std::cout << "Result: " << static_cast<int>(calculator.top()) << std::endl;
}
