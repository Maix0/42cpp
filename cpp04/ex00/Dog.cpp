/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 17:40:12 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"
#include <iostream>
#include <ostream>

Dog::Dog()
{
	this->type = "Dog";
}

Dog::~Dog() {};

Dog &Dog::operator=(Dog &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	this->type = rhs.type;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}
