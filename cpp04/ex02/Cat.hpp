/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:25:02 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 17:58:58 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "Brain.hpp"
#include <string>

/// This defines the needed function for the Orthodox canonical form
#ifdef declare_OCF
# undef declare_OCF
#endif
#define declare_OCF(ClassName)                                                 \
	ClassName();                                                               \
	~ClassName();                                                              \
	ClassName(const ClassName &);                                              \
	ClassName &operator=(ClassName &);

class Cat : public Animal
{
  public:
	declare_OCF(Cat);
	void makeSound(void) const;
	Brain *getBrain(void);

  protected:
  private:
	Brain *brain;
};

#endif /* ANIMAL_HPP */
