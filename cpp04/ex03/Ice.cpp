/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:04:49 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 16:11:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <ostream>

Ice::Ice() : AMateria("ice") {};
Ice::~Ice() {};

Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
	this->type = rhs.type;
}

Ice &Ice::operator=(const Ice &rhs)
{
	this->type = rhs.type;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
