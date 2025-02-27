/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:17:08 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/15 16:45:02 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <exception>
#include <iostream>

int main() {
  Span sp(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  {
    Span cpy(sp);
    for (size_t i = 0; i < cpy.size(); i++)
      std::cout << "Copy[" << i << "] = " << cpy[i] << std::endl;
    for (size_t i = 0; i < sp.size(); i++)
      std::cout << "Base[" << i << "] = " << sp[i] << std::endl;
  }

  Span range(20);
  std::vector<int> v;
  for (unsigned int i = 0; i < range.getMaxCapacity(); i++)
    v.push_back(i * i - i);

  range.addSpan(v.begin(), v.end());
  for (size_t i = 0; i < range.size(); i++)
    std::cout << "Base[" << i << "] = " << range[i] << std::endl;

  try {
    range.addNumber(-9999);
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
