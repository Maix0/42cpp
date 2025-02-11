/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:04:09 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/18 14:31:10 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"
class HumanB
{
public:
	HumanB(std::string name, Weapon& weapon);
	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon& weapon);
	void attack(void);

private:
	std::string name;
	Weapon*		weapon;
};

#endif /* HUMANB_HPP */
