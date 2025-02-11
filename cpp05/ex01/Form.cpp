/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:37:12 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/19 18:13:39 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

FGradeExceptionImpl(Low, "low");
FGradeExceptionImpl(High, "high");

Form::Form()
    : name("Unamed form"), is_signed(false), signGrade(1), execGrade(1) {
  this->checkGrades();
  std::cout << "Form " << COLB_GREEN << this->name
            << RESET "Has been written into stone (no, just paper...)"
            << std::endl;
};

Form::Form(std::string name, int sign, int exec)
    : name(name), is_signed(false), signGrade(sign), execGrade(exec) {
  std::cout << "Form " << COLB_GREEN << this->name
            << RESET "Has been written into stone (no, just paper...)"
            << std::endl;
  this->checkGrades();
};

Form::Form(const Form &rhs)
    : name(rhs.name), is_signed(false), signGrade(rhs.signGrade),
      execGrade(rhs.execGrade) {
  std::cout << "Form " << COLB_GREEN << this->name
            << RESET "Has been written into stone (no, just paper...)"
            << std::endl;
  this->checkGrades();
};

void Form::checkGrades() {
  if (this->execGrade < 1)
    throw Form::GradeTooHigh(this->execGrade, "exec grade");
  if (this->signGrade < 1)
    throw Form::GradeTooHigh(this->signGrade, "sign grade");
  if (this->execGrade > 150)
    throw Form::GradeTooLow(this->execGrade, "exec grade");
  if (this->signGrade > 150)
    throw Form::GradeTooLow(this->signGrade, "sign grade");
  if (this->signGrade < this->execGrade)
    throw Form::GradeTooHigh(0, "exec grade is lower than sign grade");
}

const std::string &Form::getName() const { return (this->name); };
const bool &Form::getIsSigned() const { return (this->is_signed); };
const int &Form::getSignGrade() const { return (this->signGrade); };
const int &Form::getExecGrade() const { return (this->execGrade); };

void Form::beSigned(const Bureaucrat &by) {
  if (this->is_signed) {
    std::cout << COLB_YELLOW << by.getName() << RESET << " tried to sign form "
              << COLB_GREEN << this->name << RESET
              << " but it is already signed" << std::endl;
  } else if (by.getGrade() > this->signGrade) {
    std::cout << COLB_YELLOW << by.getName() << RESET << " tried to sign form "
              << COLB_GREEN << this->name << RESET
              << " but his grade is too low "
              << "(got " << by.getGrade() << " but it requires at least "
              << this->signGrade << ")" << std::endl;
  } else {
    std::cout << COLB_YELLOW << by.getName() << RESET << " signed form "
              << COLB_GREEN << this->name << RESET << std::endl;
    this->is_signed = true;
  }
}

std::ostream &operator<<(std::ostream &lhs, Form const &rhs) {
  lhs << COLB_GREEN << rhs.getName() << RESET << ", grade to sign: " << COL_CYAN
      << rhs.getSignGrade() << RESET " grade to exec: " COL_RED
      << rhs.getExecGrade() << RESET " is signed: "
      << (rhs.getIsSigned() ? COL_GREEN "YES" : COL_RED "NO") << RESET;
  return lhs;
}
