#include "Serializer.hpp"
#include "Data.hpp"
#include <cstdint>

int main(void)
{
	std::uintptr_t raw;
	Data *data = new Data();
	Serializer serializer;
	data->a = 4;
	data->b = 10;
	data->message = "Ceci est un message de test";


	raw = serializer.serialize(data);
	std::cout << &raw << std::endl;
	std::cout << &data << std::endl;
	Data *data2 = serializer.deserialize(raw);
	std::cout << data2->message << std::endl;
	delete data2;
}