#pragma once

#include <iostream>
# include <algorithm>
# include <iostream>
# include <vector>


template <typename T>
typename T::iterator easyfind(T& content, int const value)
{
	typename T::iterator found = std::find(content.begin(), content.end(), value);
	if (found == content.end())
		throw std::invalid_argument("Error: value doesn't match any content values");
	return (found);
}