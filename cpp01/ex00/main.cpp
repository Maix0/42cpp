/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:29:13 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 18:49:20 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
int main(int argc, char *argv[])
{
	Zombie master = Zombie();
	master.announce();
	for (int i = 1; i < argc; i++)
	{
		Zombie *zom_temp = master.newZombie(std::string(argv[i]));
		zom_temp->announce();
		delete zom_temp;
	}
	master.randomChump("Eric");
}
