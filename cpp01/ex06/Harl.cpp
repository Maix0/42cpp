/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:37:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 12:58:46 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <string>

Harl::Harl()
{
	this->filter = "DEBUG";
};

Harl::~Harl() {};

std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::error(void)
{
	std::cout << "ERROR:\nLet me speak to your manager, I know best !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING:\nBe aware that I know the boss of this shop" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO:\nHi I would like to inform you that this is a private property" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "DEBUG:\ndid you know that when I was a kid, I used to read a lot. But now since I am begining to age "
				 "a log, "
				 "I can't read a lot. This "
				 "is why I buy audio books from Amazon in order to listen to the books instead of reading them. And "
				 "now you just read this whole "
				 "block of text because the correction needs it, congratutlation. This *was* useless information that "
				 "isn't even true"
			  << std::endl;
}

void Harl::setFilter(std::string level)
{
	this->filter = level;
}

void Harl::complain(std::string level)
{
	int filter_idx = std::numeric_limits<int>::max();
	int level_idx = -1;
	for (int i = 0; i < (int)(sizeof(Harl::levels) / sizeof(Harl::levels[0])); i++)
	{
		if (Harl::levels[i] == this->filter)
			filter_idx = i;
		if (Harl::levels[i] == level)
			level_idx = i;
	}
	if (level_idx < filter_idx)
		return;
	switch (level_idx)
	{
	case 0:
		Harl::debug();
		break;
	case 1:
		Harl::info();
		break;
	case 2:
		Harl::warning();
		break;
	case 3:
		Harl::error();
		break;
	}
}
