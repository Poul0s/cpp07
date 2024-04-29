/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:11 by psalame           #+#    #+#             */
/*   Updated: 2024/04/29 14:30:59 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

void	test1(int &exit_code)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	if (a != 3 || b != 2)
	{
		std::cerr << "Swap of two int failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "a = " << a << ", b = " << b << std::endl;
}

void	test2(int &exit_code)
{
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	if (c != "chaine2" || d != "chaine1")
	{
		std::cerr << "Swap of two string failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "c = " << c << ", d = " << d << std::endl;

}

void	test3(int &exit_code)
{
	int a = 2;
	int b = 3;
	int c = -1;
	int d = 2147483647;

	if (::min(a, b) != a || ::min(b, a) != a || ::min(a, c) != c || ::min(a, d) != a || ::min(b, c) != c || ::min(b, d) != b || ::min(c, d) != c)
	{
		std::cerr << "Min of two int failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
}

void	test4(int &exit_code)
{
	int a = 2;
	int b = 3;
	int c = -1;
	int d = 2147483647;

	if (::max(a, b) != b || ::max(b, a) != b || ::max(a, c) != a || ::max(a, d) != d || ::max(b, c) != b || ::max(b, d) != d || ::max(c, d) != d)
	{
		std::cerr << "Max of two int failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void	test5(int &exit_code)
{
	std::string	a = "chaine1";
	std::string	b = "chaine2";
	
	if (::min(a, b) != a || ::min(b, a) != a)
	{
		std::cerr << "Min of two string failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "min( c, d ) = " << ::min( a, b ) << std::endl;
}

void	test6(int &exit_code)
{
	std::string	a = "chaine1";
	std::string	b = "chaine2";
	
	if (::max(a, b) != b || ::max(b, a) != b)
	{
		std::cerr << "Max of two string failed." << std::endl;
		exit_code += 1;
	}
	else
		std::cout << "max( c, d ) = " << ::max( a, b ) << std::endl;
}

void	test_launcher(int &exit_code, void (*test_fct)(int &), int test_nb)
{
	int	prev_exit_code = exit_code;

	try
	{
		(*test_fct)(exit_code);
	}
	catch (std::exception &err)
	{
		exit_code += 1;
		std::cerr << "Unhandled exception in test : " << err.what() << std::endl;
	}
	if (exit_code != prev_exit_code)
		std::cout << "Test " << test_nb << " : failed." << std::endl;
	else
		std::cout << "Test " << test_nb << " : success." << std::endl;
}

int	main(void)
{
	int	exit_code = 0;
	int	test_nb = 1;

	test_launcher(exit_code, &test1, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test2, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test3, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test4, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test5, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test6, test_nb++);

	return exit_code;
}
