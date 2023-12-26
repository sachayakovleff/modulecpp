#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class Btc
{
private:
	int _year;
	int _month;
	int _day;
	int _value;
public:
	Btc();
	Btc(Btc& copy);
	~Btc();
	Btc& operator = (Btc& copy);
	void display(char *arg);
	bool validValue(std::string value);
	bool validDate(std::string date);
	float calculate() const;
};
