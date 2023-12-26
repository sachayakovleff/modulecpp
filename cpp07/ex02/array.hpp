#pragma once
#include <iostream>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int size);
	Array(Array &copy);
	~Array();
	T* getArray(void);
	unsigned int getSize(void);
	T getValue(unsigned int index);
	void setValue(T value, unsigned int index);
	void setArray(T* array);
	Array<T>& operator = (Array<T>& copy);
private:
	T*			 _array;
	unsigned int size;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& cl);

template<typename T>
Array<T>::Array(unsigned int size)
{
	this->_array = new T[size];
	this->size = size;

	for (unsigned int i = 0; _array && i < size; i++)
	{
		_array[i] = 0;
	}
}

template<typename T>
Array<T>::Array()
{
	this->_array = new T[0];
	this->size = 0;
}

template<typename T>
Array<T>::Array(Array& copy)
{
	if (*this == copy)
		return;
	if (this->_array)
		delete[] this->_array;
	this->_array = new T[copy.size];
	this->size = copy.size;
	if (!this->_array)
		return;
	for (unsigned int i  = 0; i < copy.size; i++)
		this->_array[i] = copy._array[i];
}

template<typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete[]this->_array;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>& copy)
{
	if (*this == copy)
		return (*this);
	if (this->_array)
		delete[] this->_array;
	this->_array = new T[copy.size];
	this->size = copy.size;
	if (!this->_array)
		return *this;
	for (unsigned int i = 0; i < copy.size; i++)
		this->_array[i] = copy._array[i];
	return *this;
}

template<typename T>
T* Array<T>::getArray(void)
{
	return this->_array;
}

template<typename T>
unsigned int Array<T>::getSize(void)
{
	return this->size;
}

template<typename T>
T Array<T>::getValue(unsigned int index)
{
	if (index > this->getSize())
		throw std::exception();
	return this->_array[index];
}

template<typename T>
void Array<T>::setValue(T value, unsigned int index)
{
	if (this->size > index)
		this->_array[index] = value;
	else
	{
		std::cout << "error, couldn't reach index " << index << ", out of range !" << std::endl;
		throw std::exception();
	}
}

template<typename T>
void Array<T>::setArray(T* value)
{
	if (this->_array && this->_array != value)
		delete[] _array;
	this->_array = value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, Array<T> &cl)
{
	if (!cl.getArray())
		return os;
	T *array = cl.getArray();
	for (unsigned int i = 0; i < cl.getSize(); i++)
		os << i << ": " << array[i] << std::endl;
	return (os);
}


