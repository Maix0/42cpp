/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:39:21 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/08 16:43:04 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main(int argc, char *argv[])
{
	argc--, argv++;
	for (int i = 0; i < argc; i++)
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
