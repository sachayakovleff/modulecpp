#pragma once

#include <iostream>
#include <list>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sys/time.h>

class PmergeMe
{
private:
	std::list<int> list;
	std::deque<int> deque;
	int comparisons;
	int swap;
public:
	PmergeMe();
	PmergeMe(PmergeMe &copy);
	~PmergeMe();
	PmergeMe& operator = (PmergeMe& copy);
	bool ValueIsInList(int value);
	void sort(int mergesize);
	void setlist(long unsigned int i);
	template <typename T>
	int ft_merge(long unsigned int i);
	void ft_insert();
	void calculate(int ac, char** av);
	void ft_display(std::list<int>& container);
};