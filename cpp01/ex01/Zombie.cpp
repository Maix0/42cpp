/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:28:58 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 18:51:01 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	name = std::string("Master zombie");
}

Zombie::~Zombie()
{
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *Zombie::newZombie(std::string name)
{
	Zombie *zom = new Zombie();
	zom->name = name;
	return zom;
}

void Zombie::randomChump(std::string name)
{
	Zombie *zom = Zombie::newZombie(name);
	zom->announce();
	delete zom;
}
