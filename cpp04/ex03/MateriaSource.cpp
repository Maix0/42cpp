/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:50:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 16:10:40 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>
#include <ostream>

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (rhs.storage[i] != NULL)
			this->storage[i] = rhs.storage[i]->clone();
		else
			this->storage[i] = NULL;
	}
}
MateriaSource &MateriaSource::operator=(MateriaSource &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (rhs.storage[i] != NULL)
			this->storage[i] = rhs.storage[i]->clone();
		else
			this->storage[i] = NULL;
	}
	return (*this);
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->storage[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->storage[i] != NULL)
			delete this->storage[i];
	}
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (mat == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->storage[i] == NULL)
		{
			this->storage[i] = mat;
			return;
		}
	}
	std::cout << "No slot free, the materia is deleted sadly" << std::endl;
	delete mat;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *mat = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (this->storage[i] != NULL && this->storage[i]->getType() == type)
			mat = this->storage[i];
	}
	return (mat);
}
