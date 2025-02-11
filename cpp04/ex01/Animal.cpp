/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 17:59:50 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <ostream>

Animal::Animal()
{
	this->type = "Whild animal";
}

Animal::~Animal() {};

Animal &Animal::operator=(Animal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Animal::Animal(const Animal &rhs)
{
	this->type = rhs.type;
}

void Animal::makeSound() const
{
	std::cout << "some animal noise" << std::endl;
}

const std::string &Animal::getType() const
{
	return (this->type);
};

Brain *Animal::getBrain()
{
	return (NULL);
}
