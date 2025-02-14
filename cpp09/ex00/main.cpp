/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:37 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/14 22:22:39 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "BitcoinExchange.hpp"

double get_price_at(const Date& date, const BitcoinPrices& prices) {
	const BitcoinPrices::Data& data = prices.getData();
	if (data.count(date))
		return (data.find(date)->second);
	BitcoinPrices::Data::const_iterator it = data.lower_bound(date);

	if (it == data.begin())
		return -1;
	--it;
	return (it->second);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "usage: " << (argv[0] ? argv[0] : "./btc") << " <filename>" << std::endl;
		return 1;
	}
	try {
		BitcoinPrices				 prices	  = BitcoinPrices::from_file("./data.csv");
		BitcoinHoldings				 holdings = BitcoinHoldings::from_file(argv[1]);
		const BitcoinHoldings::Data& data	  = holdings.getData();

		for (BitcoinHoldings::Data::const_iterator i = data.begin(); i != data.end(); i++) {
			double price = get_price_at(i->first, prices);
			if (price < 0.f) {
				std::cout << "Couldn't get price for " << i->second << " at " << i->first
						  << " since it is before the first recorded price !" << std::endl;
				continue;
			}
			std::cout << i->first << " = " << i->second * price << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
