/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:05:38 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 16:50:16 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"
#define NB_ENTRIES 8

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();

	void	 add_contact(Contact contact);
	Contact *get_contact(int i);

  private:
	int		cursor;
	Contact entries[NB_ENTRIES];
};

#endif /* PHONEBOOK_HPP */
