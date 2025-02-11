/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:42:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 17:53:16 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "./AMateria.hpp"

class Cure : public virtual AMateria
{
  public:
	Cure();
	Cure(const Cure &rhs);
	virtual Cure &operator=(const Cure &rhs);
	virtual ~Cure();

	virtual AMateria *clone() const;
	virtual void	  use(ICharacter &target);
};

#endif /* CURE_HPP */
