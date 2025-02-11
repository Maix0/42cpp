/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:26:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 15:39:17 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"
#include "./ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->energy = ScavTrap::energy;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Hello DiamondTrap " << COLB_BLUE << this->name << RESET
			  << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Goodbye DiamondTrap " << COLB_BLUE << this->name << RESET
			  << std::endl;
};

DiamondTrap::DiamondTrap() : ClapTrap("<Default Clap Name>_clap_name")
{
	this->name = "<Default Clap Name>";
	this->energy = ScavTrap::energy;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Hello DiamondTrap " << COLB_BLUE << this->name << RESET
			  << " default constuctor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
	: ClapTrap(rhs.name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello DiamondTrap " << COLB_BLUE << this->name << RESET
			  << " copy constuctor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &rhs)
{
	ClapTrap::name = rhs.name + "_clap_name";
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello DiamondTrap " << COLB_BLUE << this->name << RESET
			  << " assigment operator" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << COLB_BLUE << this->name << RESET
			  << " is a DIAMOND and my clap name is " << COLB_YELLOW
			  << ClapTrap::name << RESET << std::endl;
}
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
