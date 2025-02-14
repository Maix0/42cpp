/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:37 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/14 20:14:17 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "usage: " << (argv[0] ? argv[0] : "./bitcoin") << " <filename>" << std::endl;
		return 1;
	}
	BitcoinPrices prices = BitcoinPrices::from_file("./data.csv");
	BitcoinHoldings holdings = BitcoinHoldings::from_file(argv[1]);

	std::cout << holdings << std::endl;
}
