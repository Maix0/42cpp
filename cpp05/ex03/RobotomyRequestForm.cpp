/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:42:52 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/02 16:30:27 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("nfelsemb") {
  std::cout << COL_WHITE << "New default robotomy created :O" << RESET
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
  std::cout << COL_WHITE << "New robotomy form for " << BOLD COL_RED << target
            << RESET << COL_WHITE << " :O" << RESET << std::endl;
}

void RobotomyRequestForm::action(const Bureaucrat &by) const {
  std::ifstream devrandom;
  char r;
  devrandom.open(("/dev/urandom"));
  if (devrandom.fail()) {
    std::cout << COL_RED
              << "/!\\ ERROR /!\\ Coun't perform robotomy: random failed!" RESET
              << std::endl;
    return;
  }
  (void)(by);
  std::cout << "Bzzzzz.... Bzzzzz...." << std::endl;

  devrandom >> r;
  devrandom.close();
  if (r % 2) {
    std::cout << COL_RED << this->target
              << RESET
        " robotomy failed, they only got a hole in their brain now...."
              << std::endl;
  } else {
    std::cout << COL_RED << this->target << RESET " robotomy succeded !"
              << std::endl;
  }
}
