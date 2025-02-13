/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:36:11 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/11 16:46:32 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(void)
{
	std::cout << "int mutantStack: "<<std::endl;
	MutantStack<int> istack;

	for (int i = 0; i < 10; i++)
		istack.push(i * i - i);

	for (MutantStack<int>::iterator i = istack.begin(); i != istack.end(); i++)
		std::cout << *i << std::endl;

	std::cout << "\n float mutantStack: "<<std::endl;
	MutantStack<float> fstack;
	for (float i = 0; i < 10; i++)
		fstack.push(i + 1.0 / i);

	for (MutantStack<float>::iterator i = fstack.begin(); i != fstack.end(); i++)
		std::cout << *i << std::endl;

	std::cout << "\n String mutantStack: "<<std::endl;
	MutantStack<std::string> sstack;
	for (int i = 0; i < 10; i++)
	{
		std::stringstream ss;
		ss << "it is I the element at index [" << i << "] ";
		ss << "and my value is " << -i;
		sstack.push(ss.str());
	}
	for (MutantStack<std::string>::iterator i = sstack.begin(); i != sstack.end(); i++)
		std::cout << *i << std::endl;
}
