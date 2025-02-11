/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:04 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/19 17:14:57 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#include <iostream>

int main(void) {
  try {
    Bureaucrat jhon = Bureaucrat("Jhon", 66);
    Bureaucrat doe = Bureaucrat("Doe", 1);
    Form form = Form("Pet the cat", 50, 5);

    std::cout << form << std::endl;
    std::cout << jhon << std::endl;
    std::cout << doe << std::endl;

    form.beSigned(jhon);
    form.beSigned(doe);
  } catch (std::exception &err) {
    std::cerr << "Error: " << err.what() << std::endl;
  }
}
