/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:33:37 by psalame           #+#    #+#             */
/*   Updated: 2024/04/29 14:41:18 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>


template<class T>
void	iter(T *arr, size_t len, void (*f) (T &ele))
{
	for (size_t i = 0; i < len; i++)
		(*f)(arr[i]);
}

#endif