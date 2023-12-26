#pragma once

#include <stack>
#include <iostream>

class RPN
{
private:
	std::stack<double> calculator;
public:
	RPN();
	RPN(RPN& copy);
	~RPN();
	RPN& operator = (RPN& copy);
	void ft_substract(char c);
	void ft_add(char c);
	void ft_mult(char c);
	void ft_divide(char c);
	void ft_addvalue(char c);
	void calculate(char *av);
};