/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:04 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/20 16:35:59 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <iostream>

#define _SINGLE_TEST(NAME, FNAME, TY, SIGN, EXEC, do_sign)                     \
  std::cout << BOLD COLB_YELLOW "\n" #NAME ":\n - " TY ":\n" RESET             \
            << std::endl;                                                      \
  try {                                                                        \
    Bureaucrat jhon = Bureaucrat("Jhon", SIGN);                                \
    Bureaucrat doe = Bureaucrat("Doe", EXEC);                                  \
    Intern billy;                                                              \
    AForm *form = billy.makeForm(FNAME, "Bob");                                \
                                                                               \
    std::cout << *form << std::endl;                                           \
    std::cout << jhon << std::endl;                                            \
    std::cout << doe << std::endl;                                             \
                                                                               \
    if (do_sign)                                                               \
      form->beSigned(jhon);                                                    \
    doe.executeForm(*form);                                                    \
    delete form;                                                               \
  } catch (std::exception & err) {                                             \
    std::cerr << COL_RED "Error: " RESET << err.what() << std::endl;           \
  }

#define TEST_FORM(NAME, FNAME, NormalSign, NormalExec)                         \
  void test_##NAME(void) {                                                     \
    _SINGLE_TEST(NAME, FNAME, "Normal", NormalSign, NormalExec, true);         \
    _SINGLE_TEST(NAME, FNAME, "Exec Grade Too Low", NormalSign, 150, true);    \
    _SINGLE_TEST(NAME, FNAME, "Sign Grade Too Low", 150, NormalExec, true);    \
    _SINGLE_TEST(NAME, FNAME, "Not Signed", NormalSign, NormalExec, false);    \
  }

TEST_FORM(RobotomyRequestForm, "robotomy request", 66, 8);
TEST_FORM(PresidentialPardonForm, "presidential pardon", 21, 1);
TEST_FORM(ShrubberyCreationForm, "shrubbery creation", 71, 55);

int main() {
  test_RobotomyRequestForm();
  test_ShrubberyCreationForm();
  test_PresidentialPardonForm();
};
