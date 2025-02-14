/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:19 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/14 22:17:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "RPN.hpp"
int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "usage: " << (argv[0] ? argv[0] : "./RPN") << " <RPN EXPRESSION>" << std::endl;
		return 1;
	}
	try {
		long res = RPN::compute(argv[1]);
		std::cout << "Result: " << res << std::endl;
		return 0;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}
}
