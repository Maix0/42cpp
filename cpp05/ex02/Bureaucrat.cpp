/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:12 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/02 16:30:04 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

BGradeExceptionImpl(High, "high");
BGradeExceptionImpl(Low, "low");

void Bureaucrat::checkGrade(int grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHigh(grade);
  if (grade > 150)
    throw Bureaucrat::GradeTooLow(grade);
}

Bureaucrat::Bureaucrat() : name("Richard the default Name"), grade(150) {
  Bureaucrat::checkGrade(this->grade);
  std::cout << "Please welcome " << COLB_YELLOW << this->name
            << RESET " (" COL_CYAN << this->grade << RESET ")"
            << " to the world ! (default)" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {
  Bureaucrat::checkGrade(this->grade);
  std::cout << "Please welcome " << COLB_YELLOW << this->name
            << RESET " (" COL_CYAN << this->grade << RESET ")"
            << " to the world !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
  Bureaucrat::checkGrade(this->grade);
  std::cout << "Please welcome " << COLB_YELLOW << this->name
            << RESET " (" COL_CYAN << this->grade << RESET ")"
            << " to the world !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
    : name(rhs.name), grade(rhs.grade) {
  Bureaucrat::checkGrade(this->grade);
  std::cout << "Please welcome " << COLB_YELLOW << this->name
            << RESET " (" COL_CYAN << this->grade << RESET ")"
            << " to the world ! (copy)" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  Bureaucrat::checkGrade(this->grade);
  std::cout << "Goodbye " << COLB_YELLOW << this->name << RESET " (" COL_CYAN
            << this->grade << RESET ")"
            << " :(" << std::endl;
}

const std::string &Bureaucrat::getName() const { return (this->name); }
const int &Bureaucrat::getGrade() const { return (this->grade); }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  (void)(rhs);
  throw std::runtime_error("Impossible to reassign a Bureaucrat :(");
}

std::ostream &operator<<(std::ostream &lhs, Bureaucrat const &rhs) {
  lhs << COLB_YELLOW << rhs.getName() << RESET << ", grade " << COL_CYAN
      << rhs.getGrade() << RESET;
  return lhs;
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << this->name << " executed form " << form.getName() << std::endl;
  } catch (const std::exception &err) {
    std::cout << this->name << " failed to execute form " << form.getName()
              << "\nError: " << err.what() << std::endl;
  }
}

void Bureaucrat::increaseGrade() {
  checkGrade(this->grade - 1);
  this->grade--;
};
void Bureaucrat::decreaseGrade() {
  checkGrade(this->grade + 1);
  this->grade++;
};

void Bureaucrat::signForm(AForm &form) { form.beSigned(*this); }
