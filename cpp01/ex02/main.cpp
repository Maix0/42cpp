/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:00:05 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/18 14:01:31 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <ios>
#include <iostream>
#include <stdint.h>
#include <string>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "string addr: 0x" << std::hex << (uintptr_t)brain.c_str() << std::endl;
	std::cout << "string ptr:  0x" << std::hex << (uintptr_t)stringPTR << std::endl;
	std::cout << "string ref:  0x" << std::hex << (uintptr_t)&stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "string    : '" << brain << "'" << std::endl;
	std::cout << "string ptr: '" << *stringPTR << "'" << std::endl;
	std::cout << "string ref: '" << stringREF << "'" << std::endl;
}
