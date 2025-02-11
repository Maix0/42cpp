/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:40:31 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/21 13:02:47 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string input = argv[i];
		if (input.length() == 0)
		{
			std::cout << "Skipping empty argument" << std::endl;
		}
		std::cout << "Converting '" << argv[i] << "'" << std::endl;
		ScalarConverter::convert(argv[i]);
	}
}
