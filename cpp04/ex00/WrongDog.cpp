/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:26:39 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Wrong.hpp"
#include <iostream>
#include <ostream>

WrongDog::WrongDog()
{
	this->type = "WrongDog";
}

WrongDog::~WrongDog() {};

WrongDog &WrongDog::operator=(WrongDog &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongDog::WrongDog(const WrongDog &rhs) : WrongAnimal(rhs)
{
	this->type = rhs.type;
}

void WrongDog::makeSound(void) const
{
	std::cout << "WrongWoof WrongWoof" << std::endl;
}
