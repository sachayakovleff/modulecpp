#include "BitcoinExchange.hpp"
#include <vector>
#include <cmath>
#include <climits>

Btc::Btc()
{
}

Btc::Btc(Btc& copy)
{
	this->_day = copy._day;
	this->_month = copy._month;
	this->_year = copy._year;
	this->_value = copy._value;
}

Btc::~Btc()
{
}

Btc& Btc::operator=(Btc& copy)
{
	this->_day = copy._day;
	this->_month = copy._month;
	this->_year = copy._year;
	this->_value = copy._value;
	return (*this);
}

static std::vector<std::string> ft_split(std::string &line, char c)
{
	std::string args;
	std::vector<std::string> container;
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		if (*it == c)
		{
			container.push_back(args);
			args.clear();
			continue;
		}
		if (*it > 32 && *it < 127)
			args += *it;
	}
	container.push_back(args);
	return (container);
}

bool	Btc::validValue(std::string value)
{
	char* ptr = NULL;
	double doublevalue = strtod(value.c_str(), &ptr);
	if (*ptr != 0)
	{
		std::cout << "invalid value: " << value << std::endl;
		return false;
	}
	if (doublevalue > INT_MAX)
	{
		std::cout << "invalid value : not a valid number" << std::endl;
		return false;
	}
	if (doublevalue < 0 || fmod(doublevalue, 1) != 0)
	{
		std::cout << "invalid value : must be a positive integer" << std::endl;
		return false;
	}
	this->_value = static_cast <int> (doublevalue);
	return true;
}

bool dateMonthExist(double day, int month, int year)
{
	if (day <= 28 && day >= 1 && fmod(day, 1) == 1)
		return true;
	if (month == 2 && ((day == 29 && year % 4 != 0) || day > 29))
	{
		return false;
	}
	if (day == 31 && (month != 1 || month != 3 || month != 5 || month != 7 || month != 8 || month != 10 || month != 12))
	{
		return false;
	}
	if (day < 1 || day > 31)
	{
		return false;
	}
	return true;

}

bool Btc::validDate(std::string date)
{
	std::vector<std::string> splitdate = ft_split(date, '-');
	char* ptr = NULL;
	double doublevalue = strtod(splitdate[0].c_str(), &ptr);
	if (*ptr != 0 || fmod(doublevalue, 1) != 0)
	{
		std::cout << "invalid year: " << splitdate[0] << std::endl;
		return false;
	}
	if (doublevalue < 2009)
	{
		std::cout << "invalid year, must be later than 2008" << std::endl;
		return false;
	}
	if (doublevalue > 2023)
	{
		std::cout << "asking for predictions ? ;o" << std::endl;
		return false;
	}
	int year = static_cast<int>(doublevalue);
	doublevalue = strtod(splitdate[1].c_str(), &ptr);
	if (*ptr != 0)
	{
		std::cout << "invalid month: " << splitdate[1] << std::endl;
		return false;
	}
	if (doublevalue < 1 || doublevalue > 12)
	{
		std::cout << "invalid month, must be between 1 (january) and 12 (december)" << std::endl;
		return false;
	}
	int month = static_cast<int>(doublevalue);
	doublevalue = strtod(splitdate[2].c_str(), &ptr);
	if (*ptr != 0 || fmod(doublevalue, 1) != 0)
	{
		std::cout << "invalid day: " << splitdate[2] << std::endl;
		return false;
	}
	if (doublevalue < 1)
	{
		std::cout << "invalid day: must be greater than 0" << std::endl;
		return false;
	}
	if (!dateMonthExist(doublevalue, month, year))
	{
		std::cout << "day doesn't exist in this month" << std::endl;
		return false;
	}
	this->_day = static_cast<int> (doublevalue);
	this->_month = month;
	this->_year = year;
	return true;
}

float Btc::calculate() const
{
	std::fstream stream("data.csv");
	if (!stream.is_open())
	{
		std::cout << "Error: Couldn't open file: data.csv." << std::endl;
		return 0;
	}
	std::vector<std::string> db;
	std::string line;
	if (!std::getline(stream, line))
	{
		std::cout << "Error: DB is empty" << std::endl;
		return 0;
	}
	while (std::getline(stream, line))
	{
		db.push_back(line);
	}
	for (std::vector<std::string>::iterator it = db.begin(); it != db.end(); it++)
	{
		std::vector<std::string> line = ft_split(*it, ',');
		std::vector<std::string> date = ft_split(*it, '-');
		if (this->_year > static_cast<int> (strtod(date[0].c_str(), NULL)))
			continue;
		if (this->_month > static_cast<int> (strtod(date[1].c_str(), NULL)))
			continue;
		if (this->_day > static_cast<int> (strtod(date[2].c_str(), NULL)))
			continue;
		return (this->_value * strtod(line[1].c_str(), NULL));
	}
	return (0);
}

void Btc::display(char* arg)
{
	std::fstream file(arg);
	std::string line;
	if (!file.is_open())
	{
		std::cout << "Error: Couldn't open file: " << arg << "." << std::endl;
		return;
	}
	if (!std::getline(file, line))
	{
		std::cout << "Error: File " << arg << " is empty" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		std::vector<std::string> v1 = ft_split(line, '|');
		if (v1.size() != 2)
		{
			std::cout << "error: incorrect file's syntax: YYYY-MM-DD | Value" << std::endl;
			continue;
		}
		if (!this->validDate(v1[0]) || !this->validValue(v1[1]))
			continue;
		std::cout << v1[0] << " => " << v1[1] << " = " << this->calculate() << std::endl;
	}
}
