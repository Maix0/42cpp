/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:42:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 17:53:23 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "./AMateria.hpp"

class Ice : public virtual AMateria
{
  public:
	Ice();
	Ice(const Ice &rhs);
	virtual Ice &operator=(const Ice &rhs);
	virtual ~Ice();

	virtual AMateria *clone() const;
	virtual void	  use(ICharacter &target);
};

#endif /* CURE_HPP */
