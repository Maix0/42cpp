/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:15:27 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 16:06:58 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <ostream>

Character::Character() : ICharacter()
{
	this->name = "Bob didn't get a name so its the default one";
	this->slots[0] = NULL;
	this->slots[1] = NULL;
	this->slots[2] = NULL;
	this->slots[3] = NULL;
}

Character::Character(std::string name) : ICharacter()
{
	this->name = name;
	this->slots[0] = NULL;
	this->slots[1] = NULL;
	this->slots[2] = NULL;
	this->slots[3] = NULL;
}

Character::~Character() {};

Character::Character(const Character &rhs)
{
	this->name = rhs.name;
	this->slots[0] = rhs.slots[0];
	this->slots[1] = rhs.slots[1];
	this->slots[2] = rhs.slots[2];
	this->slots[3] = rhs.slots[3];
}

Character &Character::operator=(const Character &rhs)
{
	this->name = rhs.name;
	this->slots[0] = rhs.slots[0];
	this->slots[1] = rhs.slots[1];
	this->slots[2] = rhs.slots[2];
	this->slots[3] = rhs.slots[3];
	return (*this);
}
std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << this->name
				  << " tried to learn a materia that doesn't exists (NULL)"
				  << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == NULL)
		{
			this->slots[i] = m;
			return;
		}
	}
	std::cout << this->name << " has too many materia, can't add "
			  << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << this->name << " tried to unequip its materia at index "
				  << idx << ", but it doesn't exits" << std::endl;
		return;
	}
	this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << this->name << " tried to unequip its materia at index "
				  << idx << ", but it doesn't exits" << std::endl;
		return;
	}
	if (this->slots[idx] == NULL)
	{
		std::cout << this->name << " tried to unequip its materia at index "
				  << idx << ", but it doesn't exits" << std::endl;
		return;
	}

	this->slots[idx]->use(target);
}
