/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:25:02 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 18:32:41 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <string>

/// This defines the needed function for the Orthodox canonical form
#ifdef declare_OCF
# undef declare_OCF
#endif
#define declare_OCF(ClassName)                                                 \
	ClassName();                                                               \
	virtual ~ClassName();                                                      \
	ClassName(const ClassName &);                                              \
	ClassName &operator=(ClassName &);

class Animal
{
  public:
	declare_OCF(Animal);

	virtual void	   makeSound(void) const;
	const std::string &getType(void) const;
	virtual Brain	  *getBrain(void);

  protected:
	std::string type;
};

#endif /* ANIMAL_HPP */
