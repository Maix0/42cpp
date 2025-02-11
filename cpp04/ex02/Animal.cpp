/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:01 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 18:40:52 by maiboyer         ###   ########.fr       */
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

const std::string &Animal::getType() const
{
	return (this->type);
};
