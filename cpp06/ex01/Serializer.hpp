#pragma once
#include "Data.hpp"
#include <cstdint>
#include <iostream>
#include <cstring>
#include <cstdio>

class Serializer
{
public:
	Serializer();
	~Serializer();
	Serializer(Serializer& copy);
	Serializer& operator = (Serializer& copy);
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};
