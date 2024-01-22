#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->comparisons = 0;
	this->swap = 0;
}

PmergeMe::PmergeMe(PmergeMe& copy)
{
	this->list = copy.list;
	this->deque = copy.deque;
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe& PmergeMe::operator=(PmergeMe& copy)
{
	this->list = copy.list;
	this->deque = copy.deque;
	return (*this);
}

void PmergeMe::ft_display(std::list<int> &container)
{
	for (std::list<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static bool ft_isdigit(char* av)
{
	for (int i = 0; av[i]; i++)
	{
		if (av[i] < '0' || av[i] > '9')
			return false;
	}
	return true;
}

bool PmergeMe::ValueIsInList(int value)
{
	for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++)
	{
		if (*it == value)
			return (true);
	}
	return false;
}

void	PmergeMe::sort(int mergesize)
{
	long unsigned int i = 0;
	std::deque<int>::iterator it = this->deque.begin();
	std::deque<int>::iterator it2 = it;
	for (int i = 1; i < mergesize; i++)
		it2++;
	while (i < this->deque.size() - 1 && it != this->deque.end() && it2 != this->deque.end())
	{
		if (this->deque[i] > this->deque[i + 1])
		{
			std::swap(*it2, *it);
			this->sort(mergesize);
			this->swap += 1;
		}
		it++;
		it2++;
		i++;
	}
}

void	PmergeMe::setlist(long unsigned int i)
{
	long unsigned int list_index = 0;
	std::list<int>::iterator it = list.begin();
	while (list_index < i && it != list.end())
	{
		list_index++;
		it++;
	}
	for (std::deque<int>::iterator it2 = this->deque.begin(); it2 != this->deque.end(); it2++)
	{
		*it = *it2;
		it++;
	}
}

template <typename T>
int PmergeMe::ft_merge(long unsigned int mergesize)
{
	int i = 0;
	this->deque.clear();
	typedef typename std::iterator_traits<T>::value_type val_t;
	for (val_t it = this->list.begin(); it != this->list.end(); it++)
	{
		this->deque.push_back(*it);
		i++;
		if (this->deque.size() == mergesize)
		{
			this->sort(mergesize);
			this->setlist(i - mergesize);
			this->deque.clear();
		}
	}
	if (mergesize < this->list.size() && mergesize < 4)
		return (0);
	return (1);
}

template <typename T>
static int issorted(T container)
{
	std::list<int>::iterator it = container.begin();
	int currentvalue = *it;
	it++;
	int nextvalue = *it;
	while (it != container.end())
	{
		if (currentvalue > nextvalue)
		{
			return (false);
		}
		currentvalue = nextvalue;
		it++;
		nextvalue = *it;
	}
	return (true);
}


void	PmergeMe::ft_insert()
{
	std::list<int>::iterator it = --this->list.end();
	std::list<int>::iterator it2 = it;
	it2--;
	while (it != this->list.begin())
	{
		if (*it < *it2)
		{
			std::swap(*it, *it2);
			this->swap += 1;
		}
		it--;
		it2--;
	}
}

void PmergeMe::calculate(int ac, char **av)
{
	this->comparisons = 0;
	for (int i = 1; i < ac; i++)
	{
		int value = atoi(av[i]);
		if (value <= 0 || !ft_isdigit(av[i]))
		{
			std::cout << "Error: args must be positive integers!" << std::endl;
			return;
		}
		this->list.push_back(value);
	}
	std::cout << "Current: " << std::endl;
	ft_display(this->list);
	timeval tim;
	gettimeofday(&tim, NULL);
	double t1 = tim.tv_usec;
	for (long unsigned int mergesize = 2; this->ft_merge(mergesize) == 0; mergesize *= 2);
	ft_display(this->list);
	while (!issorted(this->list))
	{
		this->ft_insert();
	}
	gettimeofday(&tim, NULL);
	double t2 = tim.tv_usec;
	ft_display(this->list);
	std::cout << "number of swap: " << this->swap << std::endl;
	std::cout << "time to process a range of " << this->list.size() << "elements with std::list : " << t2 - t1 << "us" << std::endl;
}
