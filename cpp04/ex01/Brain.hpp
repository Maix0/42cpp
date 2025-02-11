/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:45:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/09 17:50:17 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#define declare_OCF(ClassName)                                                 \
	ClassName();                                                               \
	~ClassName();                                                              \
	ClassName(const ClassName &);                                              \
	ClassName &operator=(ClassName &);

class Brain
{
  public:
	declare_OCF(Brain);

	std::string *getIdea(int index);
	void		 setIdea(int index, std::string idea);

  private:
	std::string ideas[100];
};

#endif /* BRAIN_HPP */
