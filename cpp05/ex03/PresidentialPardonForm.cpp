/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:42:47 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/02 16:30:30 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresientialPardonForm", 25, 5), target("maiboyer") {
  std::cout << COLB_YELLOW << "New presiential pardon form for " << BOLD COL_RED
            << target << RESET << COLB_YELLOW << " \\o/" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresientialPardonForm", 25, 5), target(target) {
  std::cout << COLB_YELLOW << "New presiential pardon form for " << BOLD COL_RED
            << target << RESET << COLB_YELLOW << " \\o/" << RESET << std::endl;
}

void PresidentialPardonForm::action(const Bureaucrat &by) const {
  (void)(by);
  std::cout << "Information: " << COLB_YELLOW << this->target << RESET
            << " has been pardoned by " BOLD COL_GREEN "Zaphod Beeblebrox" RESET
            << std::endl;
}
