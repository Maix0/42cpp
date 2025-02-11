/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:04:12 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/18 14:35:57 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();

	const std::string& getType();
	void			   setType(std::string type);

private:
	std::string type;
};

#endif /* WEAPON_HPP */
