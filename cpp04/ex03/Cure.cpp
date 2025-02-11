/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:04:49 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 16:07:12 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <ostream>

Cure::Cure() : AMateria("cure") {};
Cure::~Cure() {};

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
	this->type = rhs.type;
}

Cure &Cure::operator=(const Cure &rhs)
{
	this->type = rhs.type;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
