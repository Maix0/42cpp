/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:04:03 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/18 14:34:34 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "./Weapon.hpp"
class HumanA
{
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void attack(void);

private:
	std::string name;
	Weapon&		weapon;
};

#endif /* HUMANA_HPP */
