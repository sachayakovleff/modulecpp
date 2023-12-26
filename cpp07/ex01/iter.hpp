#pragma once

template <typename T>
void iter(T *data, int length, void (*func)(T const &))
{
	int i = 0;
	while (i < length)
	{
		func(data[i]);
		i++;
	}
}
