/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:41 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:23:44 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_HPP
#define WRONG_HPP

#include <string>
#ifdef declare_OCF
# undef declare_OCF
#endif
#define declare_OCF(ClassName)                                                 \
	ClassName();                                                               \
	~ClassName();                                                              \
	ClassName(const ClassName &);                                              \
	ClassName &operator=(ClassName &);

class WrongAnimal
{
  public:
	declare_OCF(WrongAnimal);

	void			   makeSound(void) const;
	const std::string &getType(void) const;

  protected:
	std::string type;
};
class WrongCat : public WrongAnimal
{
  public:
	declare_OCF(WrongCat);
	void makeSound(void) const;

  protected:
};

class WrongDog : public WrongAnimal
{
  public:
	declare_OCF(WrongDog);
	void makeSound(void) const;

  protected:
};

#endif /* WRONG_HPP */
