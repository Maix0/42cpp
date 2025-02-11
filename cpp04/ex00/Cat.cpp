/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 17:41:31 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include <iostream>
#include <ostream>

Cat::Cat()
{
	this->type = "Cat";
}

Cat::~Cat() {};

Cat &Cat::operator=(Cat &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	this->type = rhs.type;
}

void Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
