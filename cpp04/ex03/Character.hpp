/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:12:35 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 16:43:39 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./AMateria.hpp"
#include "./ICharacter.hpp"

class Character : public virtual ICharacter
{
  private:
	std::string name;
	AMateria   *slots[4];

  public:
	Character(std::string name);
	Character();
	~Character();
	Character(const Character &);
	Character &operator=(const Character &rhs);

	std::string const &getName() const;
	void			   equip(AMateria *m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter &target);
};

#endif /* CHARACTER_HPP */
