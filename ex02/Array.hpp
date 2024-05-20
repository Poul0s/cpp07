/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:02 by psalame           #+#    #+#             */
/*   Updated: 2024/05/20 14:34:01 by psalame          ###   ########.fr       */
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
		const T		&operator[](unsigned int i) const;

		unsigned int	size(void) const;
	
	private:
		unsigned int	_size;
		T				*_arr;
};

#include "Array.tpp"

#endif