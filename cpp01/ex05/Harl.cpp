/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:37:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 12:55:52 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"
#include <iostream>
#include <ostream>
#include <string>

Harl::Harl() {};
Harl::~Harl() {};

std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void (Harl::*Harl::levelsFuncs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::error(void)
{
	std::cout << "Let me speak to your manager, I know best !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Be aware that I know the boss of this shop" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Hi I would like to inform you that this is a private property" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "did you know that when I was a kid, I used to read a lot. But now since I am begining to age a log, "
				 "I can't read a lot. This "
				 "is why I buy audio books from Amazon in order to listen to the books instead of reading them. And "
				 "now you just read this whole "
				 "block of text because the correction needs it, congratutlation. This *was* useless information that "
				 "isn't even true"
			  << std::endl;
}

void Harl::complain(std::string level)
{
	for (size_t i = 0; i < sizeof(Harl::levels) / sizeof(Harl::levels[0]); i++)
		if (Harl::levels[i] == level)
			(this->*Harl::levelsFuncs[i])();
}
