/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:04:57 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 17:27:38 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./colors.h"
#include "./PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>


//stolen from stack overflow: https://stackoverflow.com/a/25385766
const char* ws = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t = ws)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t = ws)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
inline std::string& trim(std::string& s, const char* t = ws)
{
    return ltrim(rtrim(s, t), t);
}

std::string truncate_string(std::string *str)
{
	if (str == NULL)
		return std::string();
	if (str->length() <= 10)
		return (*str);
	std::string out = *str;
	out.resize(9);
	out += '.';
	return out;
}

int main(void)
{
	PhoneBook	book = PhoneBook();
	std::string line;
	while (true)
	{
		if (std::cin.eof() || std::cin.fail())
			break;
		std::cout << "> ";
		std::getline(std::cin, line);
		if (line == "EXIT")
			break;
		else if (line == "")
			;
		else if (line == "SEARCH")
		{
			std::cout << std::setw(10) << "Index" << "|";
			std::cout << std::setw(10) << "FirstName" << "|";
			std::cout << std::setw(10) << "LastName" << "|";
			std::cout << std::setw(10) << "Phone" << "|";
			std::cout << std::endl;
			for (int i = 0; i < NB_ENTRIES; i++)
			{
				Contact *contact = book.get_contact(i);
				if (contact != NULL)
				{
					std::cout << std::setw(10) << i + 1 << "|";
					std::cout << std::setw(10) << truncate_string(contact->getFirstName()) << "|";
					std::cout << std::setw(10) << truncate_string(contact->getLastName()) << "|";
					std::cout << std::setw(10) << truncate_string(contact->getPhoneNumber()) << "|";
					std::cout << std::endl;
				}
			}
			std::cout << "Index to lookup: ";
			std::string index_str;
			char* end_idx;
			std::getline(std::cin, index_str);
			trim(index_str);	
			int		 index = std::strtol(index_str.c_str(), &end_idx, 10);
			Contact *contact = book.get_contact(index - 1);
			if (contact == NULL || *end_idx != 0)
			{
				std::cout << COL_RED << "Error:" << RESET " Invalid index: " << COLB_YELLOW << index_str << RESET << std::endl;
			}
			else
			{
				std::cout << "First Name:     " << contact->getFirstName()->c_str() << std::endl;
				std::cout << "Last Name:      " << contact->getLastName()->c_str() << std::endl;
				std::cout << "Phone Number:   " << contact->getPhoneNumber()->c_str() << std::endl;
				std::cout << "Darkest Secret: " << contact->getDarkestSecret()->c_str() << std::endl;
			}
		}
		else if (line == "ADD")
		{
			std::string first_name;
			std::string last_name;
			std::string phone_number;
			std::string darkest_secret;
			std::cout << COL_WHITE << "First Name: ";
			std::getline(std::cin, first_name);
			std::cout << COL_WHITE << "Last Name: ";
			std::getline(std::cin, last_name);
			std::cout << COL_WHITE << "Phone Number: ";
			std::getline(std::cin, phone_number);
			std::cout << COL_WHITE << "Deepest Darkest Secret: ";
			std::getline(std::cin, darkest_secret);

			if (first_name.length() == 0 || last_name.length() == 0 || phone_number.length() == 0 || darkest_secret.length() == 0)
			{
				std::cout << COL_RED << "Error:" << RESET << " you can't have empty fields !" << std::endl;
				continue;
			}
			book.add_contact(Contact(first_name, last_name, phone_number, darkest_secret));
		}
		else
			std::cout << COL_RED << "Unknown action: " << RESET << line << std::endl;
		line.clear();
	}
	return 0;
}
