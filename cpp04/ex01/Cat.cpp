/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 18:38:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include <iostream>
#include <ostream>

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
};

Cat &Cat::operator=(Cat &rhs)
{
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.type;
	return (*this);
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	this->brain = new Brain(*rhs.brain);
	this->type = rhs.type;
}

void Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}

Brain *Cat::getBrain(void)
{
	return (this->brain);
}
