/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:48:54 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/17 16:08:54 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "./IMateriaSource.hpp"
#include <string>
class AMateria;

class MateriaSource : public virtual IMateriaSource
{
  private:
	AMateria *storage[4];

  public:
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	MateriaSource &operator=(MateriaSource &rhs);
	virtual ~MateriaSource();
	virtual void	  learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};

#endif /* MATERIACABINET_HPP */
