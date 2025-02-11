/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 17:59:24 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"
#include <iostream>
#include <ostream>

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete this->brain;
};

Dog &Dog::operator=(Dog &rhs)
{
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.type;
	return (*this);
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.type;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}

Brain *Dog::getBrain(void)
{
	return (this->brain);
}
