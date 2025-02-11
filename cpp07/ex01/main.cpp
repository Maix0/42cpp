/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:58:49 by maiboyer          #+#    #+#             */
/*   Updated: 2025/01/06 20:39:15 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

#include <iostream>

struct Data
{
	int	 cost;
	char name[50];
	bool in_stock;
};

void print_chars(char* val)
{
	std::cout << "\t[print_char]" << val << std::endl;
}

void print_int(int val)
{
	std::cout << "\t[print_int]" << val << std::endl;
}

void print_data(Data val)
{
	std::cout << "\t[print_data] name=" << val.name << ";price=" << val.cost
			  << ";in_stock=" << (val.in_stock ? "yes" : "no") << std::endl;
}

int main(int argc, char** argv)
{
	std::cout << "print_char[" << argc - 1 << "]:" << std::endl;
	iter(argv + 1, argc - 1, print_chars);

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << "print_int[" << sizeof(arr) / sizeof(arr[0]) << "]:" << std::endl;
	iter(arr, sizeof(arr) / sizeof(arr[0]), print_int);
	std::cout << "print_int[" << 2 << "]: " << std::endl;
	iter(arr, 2, print_int);

	Data darr[] = {{20, "banana", true}, {999999, "le respect", false}, {-1, "nfelsemb", true}};

	std::cout << "print_data[" << sizeof(darr) / sizeof(darr[0]) << "]: " << std::endl;
	iter(darr, sizeof(darr) / sizeof(darr[0]), print_data);

	// NOT GOOD:
	//
	//std::cout << "print_data[" << sizeof(darr) / sizeof(darr[0]) + 50 << "]: " << std::endl;
	//iter(darr, sizeof(darr) / sizeof(darr[0]) + 50, print_data);
}
