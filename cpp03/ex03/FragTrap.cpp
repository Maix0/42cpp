/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:26:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 15:39:33 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"
#include "./ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->energy = 100;
	this->hit_points = 100;
	this->attack_damage = 30;
	std::cout << "Hello FragTrap " << COLB_BLACK << this->name << RESET
			  << std::endl;
}

FragTrap::FragTrap()
{
	this->energy = 100;
	this->hit_points = 100;
	this->attack_damage = 30;
	std::cout << "Hello FragTrap " << COLB_BLACK << this->name << RESET
			  << " default constuctor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap()
{
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello FragTrap " << COLB_BLACK << this->name << RESET
			  << " copy constuctor" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &rhs)
{
	this->name = rhs.name;
	this->energy = rhs.energy;
	this->hit_points = rhs.hit_points;
	this->attack_damage = rhs.attack_damage;
	std::cout << "Hello FragTrap " << COLB_BLACK << this->name << RESET
			  << " assigment operator" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Goodbye FragTrap " << COLB_BLACK << this->name << RESET
			  << std::endl;
};

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << COLB_BLACK << this->name << RESET
			  << " is trying to High Five you, so be kind and do it please :)"
			  << std::endl;
}
