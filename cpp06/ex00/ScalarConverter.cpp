/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:26:38 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/09 16:29:14 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

#define FILL std::left << std::setw(20)

static void _print_float(const std::string &lit) {
  const std::string special_case[4] = {"+inf", "-inf", "inf", "nan"};

  bool is_special = false;
  bool error = false;
  float value;
  for (int i = 0; i < 4; i++)
    is_special |= lit == special_case[i];
  if (is_special) {
    if (lit == "+inf" || lit == "inf")
      value = INFINITY;
    if (lit == "-inf")
      value = -INFINITY;
    if (lit == "nan")
      value = NAN;
  } else {
    char *end = NULL;
    value = std::strtof(lit.c_str(), &end);
    if (end != NULL && *end != '\0')
      error = true;
  }

  if (!error) {
    long lval = static_cast<long>(value);

    if (!(std::numeric_limits<char>::min() <= lval &&
          lval <= std::numeric_limits<char>::max()))
      std::cout << "\tchar:   " << FILL << COL_RED "char overflow" RESET
                << std::endl;
    else if (std::isprint(static_cast<char>(value)))
      std::cout << "\tchar:   " << FILL << static_cast<char>(value)
                << std::endl;
    else
      std::cout << "\tchar:   " << FILL << COL_BLUE "non printable char" RESET
                << std::endl;

    std::cout << "\tdouble: " << FILL << static_cast<double>(value)
              << std::endl;

    std::cout << "\tfloat:  " << COL_MAGENTA << FILL << value
              << RESET "<-- parsed" << std::endl;

    if (!(std::numeric_limits<int>::min() <= lval &&
          lval <= std::numeric_limits<int>::max()))
      std::cout << "\tint:    " << FILL << COL_RED "int overflow" RESET
                << std::endl;
    else
      std::cout << "\tint:    " << FILL << static_cast<int>(value) << std::endl;
  } else {
    std::cout << "There was an error in the parsing of the value \"" << lit
              << "\"" << std::endl;
  }
}

static void _print_double(const std::string &lit) {
  const std::string special_case[4] = {"+inff", "-inff", "inff", "nanf"};

  bool is_special = false;
  bool error = false;
  double value;
  for (int i = 0; i < 4; i++)
    is_special |= lit == special_case[i];
  if (is_special) {
    if (lit == "+inff" || lit == "inff")
      value = INFINITY;
    if (lit == "-inff")
      value = -INFINITY;
    if (lit == "nanf")
      value = NAN;
  } else {
    char *end = NULL;
    value = std::strtod(lit.c_str(), &end);
    if (end != NULL && *end != '\0')
      error = true;
  }

  if (!error) {
    long lval = static_cast<long>(value);

    if (!(std::numeric_limits<char>::min() <= lval &&
          lval <= std::numeric_limits<char>::max()))
      std::cout << "\tchar:   " << FILL << COL_RED "char overflow" RESET
                << std::endl;
    else if (std::isprint(static_cast<char>(value)))
      std::cout << "\tchar:   " << FILL << static_cast<char>(value)
                << std::endl;
    else
      std::cout << "\tchar:   " << FILL << COL_BLUE "non printable char" RESET
                << std::endl;

    std::cout << "\tdouble: " << COL_MAGENTA << FILL << value
              << RESET "<-- parsed" << std::endl;

    if (!(std::numeric_limits<float>::min() <= value &&
          value <= std::numeric_limits<float>::max()) &&
        !is_special)
      std::cout << "\tfloat:  " << FILL << COL_RED "float overflow" RESET
                << std::endl;
    else
      std::cout << "\tfloat:  " << FILL << static_cast<float>(value)
                << std::endl;

    if (!(std::numeric_limits<int>::min() <= lval &&
          lval <= std::numeric_limits<int>::max()))
      std::cout << "\tint:    " << FILL << COL_RED "int overflow" RESET
                << std::endl;
    else
      std::cout << "\tint:    " << FILL << static_cast<int>(value) << std::endl;
  } else {
    std::cout << "There was an error in the parsing of the value \"" << lit
              << "\"" << std::endl;
  }
}

static void _print_int(const std::string &lit) {
  bool error = false;
  long value;

  char *end = NULL;
  value = std::strtol(lit.c_str(), &end, 10);
  if (end != NULL && *end != '\0')
    error = true;

  if (!error) {
    long lval = static_cast<long>(value);

    if (!(std::numeric_limits<char>::min() <= lval &&
          lval <= std::numeric_limits<char>::max()))
      std::cout << "\tchar:   " << FILL << COL_RED "char overflow" RESET
                << std::endl;
    else if (std::isprint(static_cast<char>(value)))
      std::cout << "\tchar:   " << FILL << static_cast<char>(value)
                << std::endl;
    else
      std::cout << "\tchar:   " << FILL << COL_BLUE "non printable char" RESET
                << std::endl;

    if (!(std::numeric_limits<double>::min() <= value &&
          value <= std::numeric_limits<double>::max()))
      std::cout << "\tdouble: " << FILL << COL_RED "double overflow" RESET
                << std::endl;
    else
      std::cout << "\tdouble: " << FILL << static_cast<double>(value)
                << std::endl;

    if (!(std::numeric_limits<float>::min() <= value &&
          value <= std::numeric_limits<float>::max()))
      std::cout << "\tfloat:  " << FILL << COL_RED "float overflow" RESET
                << std::endl;
    else
      std::cout << "\tfloat:  " << FILL << static_cast<float>(value)
                << std::endl;

    if (!(std::numeric_limits<int>::min() <= lval &&
          lval <= std::numeric_limits<int>::max()))
      std::cout << "\tint:    " << FILL << COL_RED "float overflow" RESET
                << std::endl;
    else
      std::cout << "\tint:    " << COL_MAGENTA << FILL
                << static_cast<int>(value) << RESET "<-- parsed " << std::endl;
  } else {
    std::cout << "There was an error in the parsing of the value \"" << lit
              << "\"" << std::endl;
  }
}
static void _print_char(const std::string &lit) {
  bool error = false;
  long value;

  char *end = NULL;
  value = std::strtol(lit.c_str(), &end, 10);
  if (end != NULL && *end != '\0')
    error = true;

  if (!error) {
    long lval = static_cast<long>(value);

    if (!(std::numeric_limits<char>::min() <= lval &&
          lval <= std::numeric_limits<char>::max()))
      std::cout << "\tchar:   " << FILL << COL_RED "char overflow" RESET
                << RESET "<-- parsed " << std::endl;
    else if (std::isprint(static_cast<char>(value)))
      std::cout << "\tchar:   " << COL_MAGENTA << FILL
                << static_cast<char>(value) << RESET "<-- parsed " << std::endl;
    else
      std::cout << "\tchar:   " << FILL << COL_BLUE "non printable char" RESET
                << RESET "<-- parsed " << std::endl;

    if (!(std::numeric_limits<double>::min() <= value &&
          value <= std::numeric_limits<double>::max()))
      std::cout << "\tdouble: " << FILL << COL_RED "double overflow" RESET
                << std::endl;
    else
      std::cout << "\tdouble: " << FILL << static_cast<double>(value)
                << std::endl;

    if (!(std::numeric_limits<float>::min() <= value &&
          value <= std::numeric_limits<float>::max()))
      std::cout << "\tfloat:  " << FILL << COL_RED "float overflow" RESET
                << std::endl;
    else
      std::cout << "\tfloat:  " << FILL << static_cast<float>(value)
                << std::endl;

    if (!(std::numeric_limits<int>::min() <= lval &&
          lval <= std::numeric_limits<int>::max()))
      std::cout << "\tint:    " << FILL << COL_RED "float overflow" RESET
                << std::endl;
    else
      std::cout << "\tint:    " << FILL << static_cast<int>(value) << RESET
                << std::endl;
  } else {
    std::cout << "There was an error in the parsing of the value \"" << lit
              << "\"" << std::endl;
  }
}

void ScalarConverter::convert(const std::string &literal) {
  _print_float(literal);
  std::cout << std::endl;
  _print_double(literal);
  std::cout << std::endl;
  _print_char(literal);
  std::cout << std::endl;
  _print_int(literal);
  std::cout << std::endl;
}
