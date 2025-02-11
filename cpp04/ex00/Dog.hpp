/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:25:02 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:24:21 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
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

class Dog : public Animal
{
  public:
	declare_OCF(Dog);
	virtual void makeSound(void) const;

  protected:
};

#endif /* ANIMAL_HPP */
