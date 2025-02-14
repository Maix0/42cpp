/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:54:24 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/14 20:13:56 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class OutOfBoundsValue : public std::exception {
	virtual const char* what() const throw();
};
class InvalidValue : public std::exception {
	virtual const char* what() const throw();
};

struct Date {
	unsigned int y, m, d;

	bool		 operator<(const Date& rhs) const;
	bool		 operator<=(const Date& rhs) const;
	bool		 operator>(const Date& rhs) const;
	bool		 operator>=(const Date& rhs) const;
	bool		 operator==(const Date& rhs) const;
	bool		 operator!=(const Date& rhs) const;

	static Date	 parse(const std::string& string);

	class FormatError : public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidYear : public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidMonth : public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidDay : public std::exception {
		virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Date& obj);

template <typename Key, typename Value, char SEP, bool ALLOW_DUPLICATE>
class Parser {
public:
	virtual ~Parser() {};

	typedef std::multimap<Key, Value> Data;
	typedef Key					 (*ParseKey)(const std::string& s);
	typedef Value				 (*ParseValue)(const std::string& s);

private:
	const ParseKey	 pkey;
	const ParseValue pval;

protected:
	Data data;

	class ReadError : public std::exception {
		virtual const char* what() const throw() { return "Unable to read from file"; };
	};
	class InvalidFunction : public std::exception {
		virtual const char* what() const throw() { return "Invalid Function given"; };
	};
	Parser(ParseKey pkey, ParseValue pval) : pkey(pkey), pval(pval), data() {
		if (this->pval == NULL || this->pkey == NULL)
			throw InvalidFunction();
	}
	void parseFile(const std::string& filename) {
		std::ifstream file;
		file.open(filename.c_str());

		if (!file.is_open())
			throw ReadError();

		std::string line;
		// we skip the first line since it is a header containing the names of the columns
		std::getline(file, line);
		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string		  key, value;

			if (std::getline(ss, key, SEP) && std::getline(ss, value)) {
				try {
					Key	  k = this->pkey(key);
					Value v = this->pval(value);
					if (!ALLOW_DUPLICATE && this->data.count(k) != 0)
						std::cerr << "Error: " << "Duplicate keys (skipping...): " << line << std::endl;
					else
						this->data.insert(std::make_pair(k, v));
				} catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << " for line: " << line << std::endl;
				}
			} else
				std::cerr << "Error: " << "Invalid format" << " for line: " << line << std::endl;
		}
		file.close();
	};
};

class BitcoinPrices : private Parser<Date, double, ',', false> {
private:
	BitcoinPrices();

public:
	BitcoinPrices(const BitcoinPrices& rhs);
	BitcoinPrices& operator=(const BitcoinPrices& rhs);
	~BitcoinPrices();
	typedef Parser<Date, double, ',', false>::Data Data;

	const Data&								getData() const;

	/// this is the .csv file given in the subject
	static BitcoinPrices					from_file(const std::string& filename);
};

std::ostream& operator<<(std::ostream& os, const BitcoinPrices& obj);

class BitcoinHoldings : private Parser<Date, double, '|', true> {
private:
	BitcoinHoldings();

public:
	BitcoinHoldings(const BitcoinHoldings& rhs);
	BitcoinHoldings& operator=(const BitcoinHoldings& rhs);
	~BitcoinHoldings();

	typedef Parser<Date, double, '|', true>::Data Data;

	const Data&								getData() const;

	/// this is the .txt file given in the user
	static BitcoinHoldings					from_file(const std::string& filename);
};

std::ostream& operator<<(std::ostream& os, const BitcoinHoldings& obj);

#endif /* BITCOINEXCHANGE_HPP */
