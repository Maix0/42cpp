/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:01 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/15 20:38:30 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
bool easyfind(const T& c, int v) {
	typename T::const_iterator it = std::find(c.begin(), c.end(), v);
	if (it != c.end()) {
		std::cout << "Found " << v << " in the container at index " << std::distance(c.begin(), it) << std::endl;
		return (true);
	} else {
		std::cout << "Couldn't find " << v << " in the container" << std::endl;
		return (false);
	}
}

#endif /* EASYFIND_HPP */
