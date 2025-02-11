/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:49:50 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/11 16:37:09 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTATEDSTACK_HPP
#define MUTATEDSTACK_HPP

#include <stack>

template <typename T> struct MutantStack : std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator		 iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.begin();
	}

	reverse_iterator rend()
	{
		return this->c.end();
	}
};

#endif /* MUTATEDSTACK_HPP */
