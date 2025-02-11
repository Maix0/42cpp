/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:36:40 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 16:12:06 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include <string>

class AMateria;
class ICharacter
{
  public:
	virtual ~ICharacter() {};
	virtual std::string const &getName() const = 0;
	virtual void			   equip(AMateria *m) = 0;
	virtual void			   unequip(int idx) = 0;
	virtual void			   use(int idx, ICharacter &target) = 0;
};

#endif /* ICHARACTER_HPP */
