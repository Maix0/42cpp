/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:01 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/15 18:24:23 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
template <typename T> bool easyfind(const T &c, int v) {
  typename T::const_iterator val = std::find(c.begin(), c.end(), v);

  return (val != c.end());
}

#endif /* EASYFIND_HPP */
