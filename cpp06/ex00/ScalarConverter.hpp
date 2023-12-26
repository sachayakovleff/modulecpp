#pragma once

#include <iostream>

class ScalarConverter
{
public:
	~ScalarConverter();
	ScalarConverter();
	ScalarConverter(ScalarConverter& copy);
	ScalarConverter& operator = (ScalarConverter& copy);
	void convert(std::string value);
	class BadArgumentException : public std::exception {
	public:
		char* what() {
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: Impossible" << std::endl;
			std::cout << "double: Impossible" << std::endl;
			return (NULL);
		}
	};
private:
};