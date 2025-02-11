/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:29:23 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 18:47:36 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
class Zombie
{
  public:
	Zombie();
	~Zombie();
	Zombie *newZombie(std::string name);
	void	randomChump(std::string name);
	void	announce(void);

  private:
	std::string name;
};

#endif /* ZOMBIE_HPP */
