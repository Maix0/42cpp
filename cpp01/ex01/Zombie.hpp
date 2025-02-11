/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:29:23 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/17 18:51:51 by maiboyer         ###   ########.fr       */
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
	Zombie *zombieHorde(int N, std::string name);
	void	announce(void);
	void	randomChump(std::string name);

  private:
	std::string name;
};

#endif /* ZOMBIE_HPP */
