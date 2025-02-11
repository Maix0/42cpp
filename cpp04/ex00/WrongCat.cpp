/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:26:20 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Wrong.hpp"
#include <iostream>
#include <ostream>

WrongCat::WrongCat()
{
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {};

WrongCat &WrongCat::operator=(WrongCat &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal(rhs)
{
	this->type = rhs.type;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongMeow" << std::endl;
}
