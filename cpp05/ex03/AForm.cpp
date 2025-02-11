/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:37:12 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/19 18:44:06 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

FGradeExceptionImpl(Low, "low");
FGradeExceptionImpl(High, "high");

AForm::AForm()
    : name("Unamed form"), is_signed(false), signGrade(1), execGrade(1) {
  this->checkGrades();
  std::cout << "Form " << COLB_GREEN << this->name
            << RESET " Has been written into stone (no, just paper...)"
            << std::endl;
};

AForm::AForm(std::string name, int sign, int exec)
    : name(name), is_signed(false), signGrade(sign), execGrade(exec) {
  std::cout << "Form " << COLB_GREEN << this->name
            << RESET " Has been written into stone (no, just paper...)"
            << std::endl;
  this->checkGrades();
};

AForm::AForm(const AForm &rhs)
    : name(rhs.name), is_signed(false), signGrade(rhs.signGrade),
      execGrade(rhs.execGrade) {
  std::cout << "Form " << COLB_GREEN << this->name
            << RESET " Has been written into stone (no, just paper...)"
            << std::endl;
  this->checkGrades();
};

void AForm::checkGrades() {
  if (this->execGrade < 1)
    throw AForm::GradeTooHigh(this->execGrade, "exec grade");
  if (this->signGrade < 1)
    throw AForm::GradeTooHigh(this->signGrade, "sign grade");
  if (this->execGrade > 150)
    throw AForm::GradeTooLow(this->execGrade, "exec grade");
  if (this->signGrade > 150)
    throw AForm::GradeTooLow(this->signGrade, "sign grade");
  if (this->signGrade < this->execGrade)
    throw AForm::GradeTooHigh(0, "exec grade is lower than sign grade");
}

const std::string &AForm::getName() const { return (this->name); };
const bool &AForm::getIsSigned() const { return (this->is_signed); };
const int &AForm::getSignGrade() const { return (this->signGrade); };
const int &AForm::getExecGrade() const { return (this->execGrade); };

void AForm::beSigned(const Bureaucrat &by) {
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

std::ostream &operator<<(std::ostream &lhs, AForm const &rhs) {
  lhs << COLB_GREEN << rhs.getName() << RESET << ", grade to sign: " << COL_CYAN
      << rhs.getSignGrade() << RESET " grade to exec: " COL_RED
      << rhs.getExecGrade() << RESET " is signed: "
      << (rhs.getIsSigned() ? COL_GREEN "YES" : COL_RED "NO") << RESET;
  return lhs;
}

AForm::NotSigned::NotSigned() { this->message = "Form wasn't signed"; }

AForm::NotSigned::~NotSigned() throw(){};

AForm::NotSigned::NotSigned(std::string name) {
  std::stringstream ss;
  ss << "Form wasn't signed: " << name;
  this->message = ss.str();
}

const char *AForm::NotSigned::what() const throw() {
  return (this->message.c_str());
}

void AForm::execute(const Bureaucrat &by) const {
  if (!this->getIsSigned())
    throw AForm::NotSigned(this->getName());
  if (by.getGrade() > this->getExecGrade())
    throw Bureaucrat::GradeTooLow(by.getGrade());

  this->action(by);
}
