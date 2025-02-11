/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:27:16 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Wrong.hpp"
#include <iostream>
#include <ostream>

WrongAnimal::WrongAnimal()
{
	this->type = "Wild WrongAnimal";
}

WrongAnimal::~WrongAnimal() {};

WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	this->type = rhs.type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "some WrongAnimal noise" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return (this->type);
};
