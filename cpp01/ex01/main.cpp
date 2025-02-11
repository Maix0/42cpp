/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:29:13 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 18:55:55 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <string>
int main(int argc, char *argv[])
{
	Zombie master = Zombie();
	master.announce();
	int number = 5;
	if (argc >= 2)
		number = std::atoi(argv[1]);
	if (number < 0)
		number = 5;
	Zombie *horde = master.zombieHorde(number, "Zombie Horde Chump");
	for (int i = 0; i < number; i++)
	{
		horde[i].announce();
	}
	master.announce();
	delete[] horde;
}
