/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:47:12 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 12:59:17 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"
#include <iostream>
#include <ostream>

int main(int argc, char* argv[])
{
	const char* filter;
	Harl		harl = Harl();

	filter = "DEBUG";
	if (argc >= 2)
		filter = argv[1];
	harl.setFilter(filter);
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");
	return 0;
}
