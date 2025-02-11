/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:04 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/17 15:34:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
  try {
    Bureaucrat jhon = Bureaucrat("Jhon", 125);
    Bureaucrat doe = Bureaucrat("Doe", 1);
    Bureaucrat freddy = Bureaucrat("Freddy", -9);
    Bureaucrat mercury = Bureaucrat("Mercury", 151);
  } catch (std::exception &err) {
    std::cerr << "Error: " << err.what() << std::endl;
  }
}
