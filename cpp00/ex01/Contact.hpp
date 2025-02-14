/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:19:02 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 00:15:04 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  public:
	Contact();
	Contact(std::string first_name, std::string last_name, std::string phone_number, std::string darkest_secret);
	~Contact();
	void setUsed(void);
	bool isUsed(void);

	std::string *getFirstName(void);
	std::string *getLastName(void);
	std::string *getPhoneNumber(void);
	std::string *getDarkestSecret(void);

  private:
	bool		used;
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;
};

#endif /* CONTACT_HPP */
