/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:02 by psalame           #+#    #+#             */
/*   Updated: 2024/04/29 18:23:39 by psalame          ###   ########.fr       */
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

#include "Array.tpp"

#endif