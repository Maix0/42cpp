/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:36:11 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 17:55:48 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "./ICharacter.hpp"
#include <string>

class AMateria
{
  protected:
	std::string type;

  public:
	virtual ~AMateria() {};
	AMateria(std::string const &type)
	{
		this->type = type;
	};
	// Returns the materia type
	std::string const &getType() const
	{
		return (this->type);
	};
	virtual AMateria *clone() const = 0;
	virtual void	  use(ICharacter &target) = 0;
};

#endif /* AMATERIA_HPP */
