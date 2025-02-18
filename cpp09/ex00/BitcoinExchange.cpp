/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:48:21 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 13:44:18 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"
#include <climits>
#include <iomanip>

// stolen from stack overflow: https://stackoverflow.com/a/25385766
static const char*	ws = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t = ws) {
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t = ws) {
	s.erase(0, s.find_first_not_of(t));
	return s;
}

// trim from both ends of string (right then left)
inline std::string& trim(std::string& s, const char* t = ws) {
	return ltrim(rtrim(s, t), t);
}

#define IMPL_ERR(NAME, MSG)                  \
	const char* NAME::what() const throw() { \
		return MSG;                          \
	};

IMPL_ERR(Date::FormatError, "invalid date format");
IMPL_ERR(Date::InvalidYear, "invalid year");
IMPL_ERR(Date::InvalidMonth, "invalid month");
IMPL_ERR(Date::InvalidDay, "invalid Day");
IMPL_ERR(InvalidValue, "invalid value");
IMPL_ERR(OutOfBoundsValue, "value is out of bounds");

// Overload the less-than operator for total ordering
bool Date::operator<(const Date& rhs) const {
	if (this->y != rhs.y)
		return this->y < rhs.y;
	if (this->m != rhs.m)
		return this->m < rhs.m;
	return this->d < rhs.d;
}

bool Date::operator==(const Date& rhs) const {
	return (this->y == rhs.y && this->m == rhs.m && this->d == rhs.d);
};

bool Date::operator!=(const Date& other) const {
	return !(*this == other);
}
bool Date::operator>(const Date& other) const {
	return other < *this;
}
bool Date::operator<=(const Date& other) const {
	return !(*this > other);
}
bool Date::operator>=(const Date& other) const {
	return !(*this < other);
}

Date Date::parse(const std::string& raw) {
	std::string str = raw;
	trim(str);

	static const unsigned char DAY_PER_MONTH[13] = {
		29,	 // FEB_LEAP_YEAR
		31,	 // JAN
		28,	 // FEB
		31,	 // MAR
		30,	 // APR
		31,	 // MAY
		30,	 // JUN
		31,	 // JUL
		31,	 // AUG
		30,	 // SEP
		31,	 // OCT
		30,	 // NOV
		31,	 // DEC
	};

	if (str.size() != 4 + 2 + 2 + 2) {
		throw Date::FormatError();
	}
	std::stringstream ss(str);
	std::string		  sy, sm, sd;
	if (!(std::getline(ss, sy, '-') && std::getline(ss, sm, '-') && std::getline(ss, sd, '-'))) {
		throw Date::FormatError();
	}
	char *	  esy, *esm, *esd;
	long long y, m, d;

	y = std::strtoll(sy.c_str(), &esy, 10);
	m = std::strtoll(sm.c_str(), &esm, 10);
	d = std::strtoll(sd.c_str(), &esd, 10);

	if ((esy != NULL && *esy != '\0') || (esm != NULL && *esm != '\0') || (esd != NULL && *esd != '\0')) {
		throw Date::FormatError();
	}

	if (y < 0 || y > 9999) {
		throw Date::InvalidYear();
	}
	if (m < 1 || m > 12) {
		throw Date::InvalidMonth();
	}

	// change to leap year feb if leap year and feb
	long long check_month = m;
	if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && m == 2)
		check_month = 0;

	if (d < 1 || d > DAY_PER_MONTH[check_month]) {
		throw Date::InvalidDay();
	}

	Date out;
	out.y = y;
	out.m = m;
	out.d = d;
	return (out);
}

std::ostream& operator<<(std::ostream& os, const Date& obj) {
	return os << std::setfill('0') << std::setw(4) << obj.y << "-" << std::setfill('0') << std::setw(2) << obj.m << "-" << std::setfill('0')
			  << std::setw(2) << obj.d;
}

template <int64_t MIN, int64_t MAX>
static double _parse_double(const std::string& raw) {
	std::string str = raw;
	trim(str);

	char*  end;
	double value = strtod(str.c_str(), &end);
	if (end != NULL && *end != '\0')
		throw InvalidValue();
	if (value < MIN || value > MAX)
		throw OutOfBoundsValue();
	return value;
}

BitcoinPrices::~BitcoinPrices() {};
BitcoinPrices::BitcoinPrices() : Parser(Date::parse, _parse_double<0, UINT_MAX>, NULL) {};
BitcoinPrices::BitcoinPrices(const BitcoinPrices& rhs) : Parser(Date::parse, _parse_double<0, UINT_MAX>, NULL) {
	this->data = rhs.data;
};

BitcoinPrices& BitcoinPrices::operator=(const BitcoinPrices& rhs) {
	this->data = rhs.data;
	return (*this);
}

BitcoinPrices BitcoinPrices::from_file(const std::string& filename) {
	BitcoinPrices out;
	int			  dummy = 0;

	out.parseFile(filename, dummy);
	return out;
}

const BitcoinPrices::Data& BitcoinPrices::getData() const {
	return (this->data);
}

std::ostream& operator<<(std::ostream& os, const BitcoinPrices& obj) {
	const BitcoinPrices::Data& data = obj.getData();

	for (BitcoinPrices::Data::const_iterator i = data.begin(); i != data.end(); i++) {
		std::cout << i->first << " => " << i->second << std::endl;
	}
	return (os);
}

static double _get_price_at(const Date& date, const BitcoinPrices& prices) {
	const BitcoinPrices::Data& data = prices.getData();
	if (data.count(date))
		return (data.find(date)->second);
	BitcoinPrices::Data::const_iterator it = data.lower_bound(date);

	if (it == data.begin())
		return -1;
	--it;
	return (it->second);
}

static bool _valid_state(const Date& date, const double& holding, const BitcoinPrices& prices) {
	double price = _get_price_at(date, prices);
	if (price < 0.f) {
		std::cout << COLB_YELLOW "Couldn't get price for " << holding << " at " << date
				  << " since it is before the first recorded price !" RESET << std::endl;
		return false;
	}
	std::cout << GREEN << date << " = $" << holding * price << RESET << std::endl;
	return (true);
}

BitcoinHoldings::~BitcoinHoldings() {};
BitcoinHoldings::BitcoinHoldings() : Parser(Date::parse, _parse_double<0, 1000>, _valid_state) {};
BitcoinHoldings::BitcoinHoldings(const BitcoinHoldings& rhs) : Parser(Date::parse, _parse_double<0, 1000>, _valid_state) {
	this->data = rhs.data;
};

BitcoinHoldings& BitcoinHoldings::operator=(const BitcoinHoldings& rhs) {
	this->data = rhs.data;
	return (*this);
}

BitcoinHoldings BitcoinHoldings::from_file(const std::string& filename, const BitcoinPrices& prices) {
	BitcoinHoldings out;

	out.parseFile(filename, prices);
	return out;
}

const BitcoinHoldings::Data& BitcoinHoldings::getData() const {
	return (this->data);
}

std::ostream& operator<<(std::ostream& os, const BitcoinHoldings& obj) {
	const BitcoinHoldings::Data& data = obj.getData();

	for (BitcoinHoldings::Data::const_iterator i = data.begin(); i != data.end(); i++) {
		std::cout << i->first << " => " << i->second << std::endl;
	}
	return (os);
}
