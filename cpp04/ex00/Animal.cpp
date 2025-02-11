/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:27:26 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include <iostream>
#include <ostream>

Animal::Animal()
{
	this->type = "Wild Animal";
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
	std::cout << "some Animal noise" << std::endl;
}

const std::string &Animal::getType() const
{
	return (this->type);
};
