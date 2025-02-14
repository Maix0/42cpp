/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:18:34 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 13:08:43 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

Contact::~Contact() {};

Contact::Contact()
{
	this->used = false;
	this->first_name = std::string();
	this->last_name = std::string();
	this->phone_number = std::string();
	this->darkest_secret = std::string();
}

Contact::Contact(std::string first_name, std::string last_name, std::string phone_number, std::string darkest_secret)
{
	this->used = true;
	this->first_name = first_name;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void Contact::setUsed(void)
{
	this->used = true;
}

bool Contact::isUsed(void)
{
	return this->used;
}

std::string *Contact::getFirstName(void)
{
	return (&this->first_name);
}

std::string *Contact::getLastName(void)
{
	return (&this->last_name);
}

std::string *Contact::getPhoneNumber(void)
{
	return (&this->phone_number);
}

std::string *Contact::getDarkestSecret(void)
{
	return (&this->darkest_secret);
}
