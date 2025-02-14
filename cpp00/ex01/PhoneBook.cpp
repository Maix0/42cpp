/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:08:32 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/16 23:50:27 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->cursor = 0;
	for (int i = 0; i < NB_ENTRIES; i++)
		this->entries[i] = Contact();
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(Contact contact)
{
	this->entries[this->cursor] = contact;
	this->entries[this->cursor].setUsed();

	this->cursor += 1;
	if (this->cursor == NB_ENTRIES)
		this->cursor = 0;
}

Contact *PhoneBook::get_contact(int i)
{
	if (i >= NB_ENTRIES || i < 0)
		return NULL;

	Contact *entry = &this->entries[i];
	if (entry->isUsed())
		return entry;
	else
		return NULL;
}
