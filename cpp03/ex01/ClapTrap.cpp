/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:26:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 15:27:13 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	this->name = "<Default Clap Name>";
	this->energy = 10;
	this->hit_points = 10;
	this->attack_damage = 0;
	std::cout << "Hello ClapTrap " << COLB_YELLOW << this->name << RESET
			  << " default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello ClapTrap " << COLB_YELLOW << this->name << RESET
			  << " copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &rhs)
{
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello ClapTrap " << COLB_YELLOW << this->name << RESET
			  << " operator=()" << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->energy = 10;
	this->hit_points = 10;
	this->attack_damage = 0;
	std::cout << "Hello ClapTrap " << COLB_YELLOW << this->name << RESET
			  << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Goodbye ClapTrap " << COLB_YELLOW << this->name << RESET
			  << std::endl;
};

void ClapTrap::attack(const std::string &target)
{
	if (this->energy > 0)
	{
		this->energy--;
		std::cout << "ClapTrap ";
		std::cout << COLB_YELLOW << this->name << RESET;
		std::cout << " attacks ";
		std::cout << COLB_GREEN << target << RESET;
		std::cout << ", causing ";
		std::cout << COL_RED << this->attack_damage << RESET;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap ";
		std::cout << COLB_YELLOW << this->name << RESET;
		std::cout << " tried to attacks ";
		std::cout << COLB_GREEN << target << RESET;
		std::cout << " but it has no energy left or hit point left (sadge)!"
				  << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	if (this->hit_points < 0)
		this->hit_points = 0;
	std::cout << "ClapTrap ";
	std::cout << COLB_YELLOW << this->name << RESET;
	std::cout << " receives ";
	std::cout << COL_RED << amount << RESET;
	std::cout << " damage. They now have ";
	std::cout << COL_RED << this->hit_points << RESET;
	std::cout << " hit point!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->hit_points > 0)
	{
		this->hit_points += amount;
		this->energy--;
		std::cout << "ClapTrap ";
		std::cout << COLB_YELLOW << this->name << RESET;
		std::cout << " repair itself for ";
		std::cout << COL_RED << amount << RESET;
		std::cout << " points , they now have ";
		std::cout << COL_RED << this->hit_points << RESET;
		std::cout << " hit points !" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap ";
		std::cout << COLB_YELLOW << this->name << RESET;
		std::cout << " tried to repair itself for ";
		std::cout << COL_RED << amount << RESET;
		std::cout << " but it has no energy left or hit point left (sadge)!"
				  << std::endl;
	}
}
