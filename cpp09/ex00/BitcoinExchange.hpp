/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:54:24 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 13:46:58 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define RESET		   "\x1b[0m"
#define BOLD		   "\x1b[1m"
#define WEAK		   "\x1b[2m"
#define ITALIC		   "\x1b[3m"
#define UNDERLINE	   "\x1b[4m"

#define BLACK		   "\x1b[30m"
#define RED			   "\x1b[31m"
#define GREEN		   "\x1b[32m"
#define YELLOW		   "\x1b[33m"
#define BLUE		   "\x1b[34m"
#define MAGENTA		   "\x1b[35m"
#define CYAN		   "\x1b[36m"
#define WHITE		   "\x1b[37m"

#define COLB_BLACK	   "\x1b[90m"
#define COLB_RED	   "\x1b[91m"
#define COLB_GREEN	   "\x1b[92m"
#define COLB_YELLOW	   "\x1b[93m"
#define COLB_BLUE	   "\x1b[94m"
#define COLB_MAGENTA   "\x1b[95m"
#define COLB_CYAN	   "\x1b[96m"
#define COLB_WHITE	   "\x1b[97m"

#define COLBG_BLACK	   "\x1b[40m"
#define COLBG_RED	   "\x1b[41m"
#define COLBG_GREEN	   "\x1b[42m"
#define COLBG_YELLOW   "\x1b[43m"
#define COLBG_BLUE	   "\x1b[44m"
#define COLBG_MAGENTA  "\x1b[45m"
#define COLBG_CYAN	   "\x1b[46m"
#define COLBG_WHITE	   "\x1b[47m"

#define COLBBG_BLACK   "\x1b[10m0"
#define COLBBG_RED	   "\x1b[10m1"
#define COLBBG_GREEN   "\x1b[10m2"
#define COLBBG_YELLOW  "\x1b[10m3"
#define COLBBG_BLUE	   "\x1b[10m4"
#define COLBBG_MAGENTA "\x1b[10m5"
#define COLBBG_CYAN	   "\x1b[10m6"
#define COLBBG_WHITE   "\x1b[10m7"

#include <algorithm>
#include <cstddef>
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

template <typename Key, typename Value, typename State, char SEP, bool ALLOW_DUPLICATE>
class Parser {
public:
	virtual ~Parser() {};

	typedef std::multimap<Key, Value> Data;
	typedef Key						  (*ParseKey)(const std::string& s);
	typedef Value					  (*ParseValue)(const std::string& s);
	typedef bool					  (*ValidateValues)(const Key& k, const Value& v, State& state);

private:
	const ParseKey		 pkey;
	const ParseValue	 pval;
	const ValidateValues val_func;

protected:
	Data data;

	class ReadError : public std::exception {
		virtual const char* what() const throw() { return "Unable to read from file"; };
	};
	class InvalidFunction : public std::exception {
		virtual const char* what() const throw() { return "Invalid Function given"; };
	};
	Parser(ParseKey pkey, ParseValue pval, ValidateValues val_func) : pkey(pkey), pval(pval), val_func(val_func), data() {
		if (this->pval == NULL || this->pkey == NULL)
			throw InvalidFunction();
	}
	void parseFile(const std::string& filename, State& state) {
		std::ifstream file;
		file.open(filename.c_str());

		if (!file.is_open())
			throw ReadError();

		std::string line;
		// we skip the first line since it is a header containing the names of the columns
		std::getline(file, line);
		std::size_t i = 0;
		std::cout << "\nParsing file " << filename << ":" << std::endl;
		while (i++, std::getline(file, line)) {
			std::stringstream ss(line);
			std::string		  key, value;

			if (std::getline(ss, key, SEP) && std::getline(ss, value)) {
				try {
					Key	  k = this->pkey(key);
					Value v = this->pval(value);
					if (!ALLOW_DUPLICATE && this->data.count(k) != 0)
						std::cerr << RED BOLD "Error" RESET ": " << "Duplicate keys on line " << i << " (skipping...): " COLB_BLACK << line
								  << RESET << std::endl;
					else {
						if (this->val_func == NULL || this->val_func(k, v, state))
							this->data.insert(std::make_pair(k, v));
					}
				} catch (const std::exception& e) {
					std::cerr << RED BOLD "Error" RESET ": " << e.what() << " for line " << i << ": " COLB_BLACK << line << RESET
							  << std::endl;
				}
			} else
				std::cerr << RED BOLD "Error" RESET ": " << "Invalid format" << " for line " << i << ": " COLB_BLACK << line << RESET
						  << std::endl;
		}
		file.close();
	};
};

class BitcoinPrices : private Parser<Date, double, int, ',', false> {
private:
	BitcoinPrices();

public:
	BitcoinPrices(const BitcoinPrices& rhs);
	BitcoinPrices& operator=(const BitcoinPrices& rhs);
	~BitcoinPrices();
	typedef Parser<Date, double, int, ',', false>::Data Data;

	const Data&											getData() const;

	/// this is the .csv file given in the subject
	static BitcoinPrices								from_file(const std::string& filename);
};

std::ostream& operator<<(std::ostream& os, const BitcoinPrices& obj);

class BitcoinHoldings : private Parser<Date, double, const BitcoinPrices&, '|', true> {
private:
	BitcoinHoldings();

public:
	BitcoinHoldings(const BitcoinHoldings& rhs);
	BitcoinHoldings& operator=(const BitcoinHoldings& rhs);
	~BitcoinHoldings();

	typedef Parser<Date, double, const BitcoinPrices&, '|', true>::Data Data;

	const Data&															getData() const;

	/// this is the .txt file given in the user
	static BitcoinHoldings												from_file(const std::string& filename, const BitcoinPrices& prices);
};

std::ostream& operator<<(std::ostream& os, const BitcoinHoldings& obj);

#endif /* BITCOINEXCHANGE_HPP */
