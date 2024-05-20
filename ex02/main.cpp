/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:11 by psalame           #+#    #+#             */
/*   Updated: 2024/05/20 14:33:26 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>


void	test1(int &exit_code)
{
	Array<std::string>	arr;

	if (arr.size() != 0)
	{
		exit_code++;
		std::cerr << "Array size isnt equal to 0." << std::endl;
	}
}

void	test2(int &exit_code)
{
	Array<std::string>	arr(3);
	std::string			str0 = "str0";
	std::string			str1 = "str1";
	std::string			str2 = "str2";
	arr[0] = str0;
	arr[1] = str1;
	arr[2] = str2;

	if (arr[0] != str0 || arr[1] != str1 || arr[2] != str2 || arr.size() != 3)
	{
		exit_code++;
		std::cerr << "Value of array after set them are invalid." << std::endl;
	}
}

void	test3(int &exit_code)
{
	Array<std::string>	arr(1);
	arr[0] = "a random string";

	try
	{
		std::string a = arr[-1];
		exit_code++;
		std::cerr << "Can access array in index out of bounds" << std::endl;
	}
	catch (std::exception &err)
	{
	}

}

void	test4(int &exit_code)
{
	Array<std::string>	arr(1);
	arr[0] = "a random string";

	try
	{
		std::string a = arr[1];
		exit_code++;
		std::cerr << "Can access array in index out of bounds" << std::endl;
	}
	catch (std::exception &err)
	{
	}
}

void	test5(int &exit_code)
{
	Array<std::string>	arr(2);
	std::string			str0 = "str0";
	std::string			str1 = "str1";
	arr[0] = str0;
	arr[1] = str1;

	const Array<std::string>	arrCopy(arr);
	if (arrCopy[0] != str0 || arrCopy[1] != str1 || arrCopy.size() != arr.size())
	{
		exit_code++;
		std::cerr << "Array copy constructor doesnt set value properly" << std::endl;
	}
}

void	test6(int &exit_code)
{
	Array<std::string>	arr(2);
	std::string			str0 = "str0";
	std::string			str1 = "str1";
	arr[0] = str0;
	arr[1] = str1;
	Array<std::string>	arrCopy(9);

	arrCopy = arr;
	if (arrCopy[0] != str0 || arrCopy[1] != str1 || arrCopy.size() != arr.size())
	{
		exit_code++;
		std::cerr << "Array copy operator doesnt set value properly" << std::endl;
	}
}

void	test7(int &exit_code)
{
	Array<std::string>	arr(2);
	std::string			str0 = "str0";
	std::string			str1 = "str1";
	arr[0] = str0;
	arr[1] = str1;
	Array<std::string>	arrCopy;

	arrCopy = arr;
	if (arrCopy[0] != str0 || arrCopy[1] != str1 || arrCopy.size() != arr.size())
	{
		exit_code++;
		std::cerr << "Array copy operator doesnt set value properly" << std::endl;
	}
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
	std::cout << std::endl;
	test_launcher(exit_code, &test7, test_nb++);

	return exit_code;
}
