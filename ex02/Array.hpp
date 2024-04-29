/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:02 by psalame           #+#    #+#             */
/*   Updated: 2024/04/29 17:00:06 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstddef>
# include <exception>

template<class T>
class Array {
	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array &copy);
		~Array(void);

		Array	&operator=(const Array &copy);
		T		&operator[](unsigned int i);

		unsigned int	size(void);
	
	private:
		unsigned int	_size;
		T				*_arr;
};


// constructors definitions

template<class T>
Array<T>::Array(void)
{
	this->_size = 0;
	this->_arr = NULL;
}

template<class T>
Array<T>::Array(unsigned int size)
{
	this->_size = size;
	this->_arr = new T[size];
	if (!this->_arr)
		throw std::exception();
}

template<class T>
Array<T>::Array(const Array &copy)
{
	this->_arr = NULL;
	*this = copy;
}

template<class T>
Array<T>::~Array(void)
{
	if (this->_arr)
		delete[] this->_arr;
}


// Operator overload

template<class T>
Array<T>	&Array<T>::operator=(const Array &copy)
{
	if (this->_arr != NULL)
		delete[] this->_arr;

	this->_size = copy._size;
	this->_arr = new T[copy._size];
	if (!this->_arr)
		throw std::exception();
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = copy._arr[i];

	return (*this);
}

template<class T>
T		&Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw std::exception();
	return (this->_arr[i]);
}


// member function

template<class T>
unsigned int	Array<T>::size(void)
{
	return this->_size;
}

#endif