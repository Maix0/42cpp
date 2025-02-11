/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:01 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/10 15:36:45 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
template <typename T> bool easyfind(T& containers, int value)
{
	int idx = 0;
	for (typename T::iterator i = containers.begin(); i != containers.end(); ++i)
	{
		if (*i == value)
		{
			std::cout << "Found element " << value << " at index " << idx << std::endl;
			return true;
		}
		idx++;
	}
	std::cout << "Couldn't find element " << value << " after searching " << idx << " elements..." << std::endl;
	return false;
}

#endif /* EASYFIND_HPP */
