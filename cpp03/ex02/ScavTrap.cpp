/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:26:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 15:25:54 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"
#include "./ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->energy = 50;
	this->hit_points = 100;
	this->attack_damage = 20;
	std::cout << "Hello ScavTrap " << COLB_MAGENTA << this->name << RESET
			  << std::endl;
}

ScavTrap::ScavTrap()
{
	this->energy = 50;
	this->hit_points = 100;
	this->attack_damage = 20;
	std::cout << "Hello ScavTrap " << COLB_MAGENTA << this->name << RESET
			  << " default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello ScavTrap " << COLB_MAGENTA << this->name << RESET
			  << " copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &rhs)
{
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello ScavTrap " << COLB_MAGENTA << this->name << RESET
			  << " assigment operator" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Goodbye ScavTrap " << COLB_MAGENTA << this->name << RESET
			  << std::endl;
};

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << COLB_MAGENTA << this->name << RESET
			  << " is now guarding the gate !" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy > 0 && this->hit_points > 0)
	{
		this->energy--;
		std::cout << "ScavTrap ";
		std::cout << COLB_MAGENTA << this->name << RESET;
		std::cout << " attacks ";
		std::cout << COLB_GREEN << target << RESET;
		std::cout << ", causing ";
		std::cout << COL_RED << this->attack_damage << RESET;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap ";
		std::cout << COLB_MAGENTA << this->name << RESET;
		std::cout << " tried to attacks ";
		std::cout << COLB_GREEN << target << RESET;
		std::cout << " but it has no energy left or hit point left (sadge)!"
				  << std::endl;
	}
}
