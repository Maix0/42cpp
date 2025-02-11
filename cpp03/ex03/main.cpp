/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:39:21 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 15:40:59 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(int argc, char *argv[])
{
	argc--, argv++;
	for (int i = 0; i < argc; i++)
	{
		int selector = i % 4;
		if (selector == 0)
		{
			DiamondTrap trap(argv[i]);

			trap.attack("The Corrector");
			trap.takeDamage(1);
			trap.beRepaired(9);
			trap.attack("Itself");
			trap.beRepaired(1);
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.highFivesGuys();
			trap.guardGate();
			trap.whoAmI();
		}
		else if (selector == 1)
		{
			FragTrap trap(argv[i]);

			trap.attack("The Corrector");
			trap.takeDamage(1);
			trap.beRepaired(9);
			trap.attack("Itself");
			trap.beRepaired(1);
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.highFivesGuys();
		}
		else if (selector == 2)
		{
			ScavTrap trap(argv[i]);

			trap.attack("The Corrector");
			trap.takeDamage(1);
			trap.beRepaired(9);
			trap.attack("Itself");
			trap.beRepaired(1);
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.guardGate();
		}
		else if (selector == 3)
		{
			ClapTrap trap(argv[i]);

			trap.attack("The Corrector");
			trap.takeDamage(1);
			trap.beRepaired(9);
			trap.attack("Itself");
			trap.beRepaired(1);
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
			trap.attack("My Sanity");
		}
	}
}
