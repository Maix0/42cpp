/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:37 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 13:43:11 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "usage: " << (argv[0] ? argv[0] : "./btc") << " <filename>" << std::endl;
		return 1;
	}
	try {
		BitcoinPrices				 prices	  = BitcoinPrices::from_file("./data.csv");
		BitcoinHoldings				 holdings = BitcoinHoldings::from_file(argv[1], prices);
		const BitcoinHoldings::Data& data	  = holdings.getData();

		std::cout << std::endl;
		for (BitcoinHoldings::Data::const_iterator i = data.begin(); i != data.end(); i++) {
		}
	} catch (const std::exception& e) {
		std::cerr << BOLD RED "Error" RESET ": " << e.what() << std::endl;
	}
}
