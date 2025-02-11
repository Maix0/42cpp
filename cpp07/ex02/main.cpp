/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:56:58 by maiboyer          #+#    #+#             */
/*   Updated: 2025/01/06 21:19:56 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iomanip>
#include <iostream>

int main(void)
{
	Array<int> empty;
	std::cout << "size=" << empty.size() << ";elem=" << empty[0] << std::endl << std::endl;
	Array<bool> bempty;
	std::cout << "size=" << bempty.size() << ";elem=" << bempty[0] << std::endl << std::endl;
	Array<std::string> sempty;
	std::cout << "size=" << sempty.size() << ";elem=" << sempty[0] << std::endl << std::endl;

	Array<int> arr = Array<int>(10);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * i;
	Array<int> copy = Array<int>(arr);
	for (unsigned int i = 0; i < copy.size(); i++)
		copy[i] += i;

	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "Arr" << "|" << std::setw(10) << "Copy"
			  << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << std::setw(10) << i << "|" << std::setw(10) << arr[i] << "|" << std::setw(10) << copy[i]
				  << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	Array<double> darr = Array<double>(7);
	for (unsigned int i = 0; i < darr.size(); i++)
		darr[i] = i * i;
	Array<double> dcopy = Array<double>(darr);
	for (unsigned int i = 0; i < dcopy.size(); i++)
		dcopy[i] += 1.0 / (double)i;
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "Arr" << "|" << std::setw(10) << "Copy"
			  << std::endl;
	for (unsigned int i = 0; i < dcopy.size(); i++)
		std::cout << std::setw(10) << i << "|" << std::setw(10) << darr[i] << "|" << std::setw(10) << dcopy[i]
				  << std::endl;

	try
	{
		darr[darr.size() + 105] = 1;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR1: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "hello: " << darr[darr.size()] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR2: " << e.what() << std::endl;
	}
}
