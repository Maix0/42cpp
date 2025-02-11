/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:21:32 by maiboyer          #+#    #+#             */
/*   Updated: 2025/01/29 17:37:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

AForm *robotomy_request(std::string target) {
  return new RobotomyRequestForm(target);
}
AForm *presidential_pardon(std::string target) {
  return new PresidentialPardonForm(target);
}
AForm *shrubbery_creation(std::string target) {
  return new ShrubberyCreationForm(target);
}

static const Pair forms[3] = {{"robotomy_requestt", robotomy_request},
                              {"presidential_pardon", presidential_pardon},
                              {"shrubbery_creation", shrubbery_creation}};

AForm *Intern::makeForm(std::string form, std::string target) const {
  for (int i = 0; i < 3; i++) {
    if (form == forms[i].form) {
      std::cout << "Intern created form" << form << std::endl;
      return forms[i].make(target);
    }
  }
  std::cout << "Intern tried to create form" << form
            << "but it doesn't exits..." << std::endl;
  return NULL;
}
