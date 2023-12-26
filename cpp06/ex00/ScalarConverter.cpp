#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& copy)
{
	*this = copy;
	return (*this);
}

static double	getDouble(std::string value)
{
	char* endPtr;
	double doublevalue = strtod(value.c_str(), &endPtr);

	if (endPtr != 0 && ((endPtr[0] == 'f' && endPtr[1] != 0) || (endPtr[0] != 0 && endPtr[0] != 'f'))) {
		throw(ScalarConverter::BadArgumentException());
	}
	else {
		std::cout << "value == " << doublevalue << std::endl;
	}
	return doublevalue ;
}

static std::string	getChar(double value)
{
	if (value < 0 || value > 126 || value != static_cast <char> (value))
		return "impossible";
	else if (value <= 32 || value >= 127)
		return "unprintable";
	else
	{
		char c = static_cast <int> (value);
		std::string result(1, c);
		return (result);
	}
}

static std::string	getInt(double value)
{
	if (value == std::isfinite(value))
		return ("Overflow");
	if ((fmod(value, 1.0)) != 0 || std::isnan(value))
		return ("Impossible");
	if (value != static_cast <int> (value))
		return ("Overflow");
	std::stringstream ss;
	ss << static_cast <int> (value);
	std::string result;
	ss >> result;
	return (result);
}

static std::string	getFloat(double value)
{
	std::stringstream ss;
	ss << static_cast < float> (value);
	std::string result;
	ss >> result;
	if (fmod(value, 1.0) != 0)
		result.append("f");
	else
		result.append(".0f");
	return (result);
}

void ScalarConverter::convert(std::string value)
{
	try
	{
		double doublevalue = getDouble(value);
		std::cout << "char: " << getChar(doublevalue) << std::endl;
		std::cout << "int: " << getInt(doublevalue) << std::endl;
		std::cout << "float: " << getFloat(doublevalue) << std::endl;
		std::cout << "double: " << doublevalue;
		if (fmod(doublevalue, 1) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (ScalarConverter::BadArgumentException& e)
	{
		e.what();
	}
}

