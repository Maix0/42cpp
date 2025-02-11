/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:04 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/20 16:07:45 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <iostream>

#define TEST_FORM(NAME, NormalSign, NormalExec)                                \
  void test_##NAME(void) {                                                     \
    std::cout << BOLD COLB_YELLOW "\n" #NAME ":\n - Normal:\n" RESET           \
              << std::endl;                                                    \
    try {                                                                      \
      Bureaucrat jhon = Bureaucrat("Jhon", NormalSign);                        \
      Bureaucrat doe = Bureaucrat("Doe", NormalExec);                          \
      AForm *form = new NAME("Bob");                                           \
      std::cout << *form << std::endl;                                         \
      std::cout << jhon << std::endl;                                          \
      std::cout << doe << std::endl;                                           \
                                                                               \
      form->beSigned(jhon);                                                    \
      doe.executeForm(*form);                                                  \
      delete form;                                                             \
    } catch (std::exception & err) {                                           \
      std::cerr << COL_RED "Error: " RESET << err.what() << std::endl;         \
    }                                                                          \
                                                                               \
    std::cout << BOLD COLB_YELLOW "\n" #NAME                                   \
                                  ":\n - Execute Grade Too Low:\n" RESET       \
              << std::endl;                                                    \
    try {                                                                      \
      Bureaucrat jhon = Bureaucrat("Jhon", NormalSign);                        \
      Bureaucrat doe = Bureaucrat("Doe", 150);                                 \
      AForm *form = new NAME("Bob");                                           \
                                                                               \
      std::cout << *form << std::endl;                                         \
      std::cout << jhon << std::endl;                                          \
      std::cout << doe << std::endl;                                           \
                                                                               \
      form->beSigned(jhon);                                                    \
      doe.executeForm(*form);                                                  \
      delete form;                                                             \
    } catch (std::exception & err) {                                           \
      std::cerr << COL_RED "Error: " RESET << err.what() << std::endl;         \
    }                                                                          \
                                                                               \
    std::cout << BOLD COLB_YELLOW "\n" #NAME                                   \
                                  ":\n - Sign Grade Too Low:\n" RESET          \
              << std::endl;                                                    \
    try {                                                                      \
      Bureaucrat jhon = Bureaucrat("Jhon", 150);                               \
      Bureaucrat doe = Bureaucrat("Doe", NormalExec);                          \
      AForm *form = new NAME("Bob");                                           \
                                                                               \
      std::cout << *form << std::endl;                                         \
      std::cout << jhon << std::endl;                                          \
      std::cout << doe << std::endl;                                           \
                                                                               \
      form->beSigned(jhon);                                                    \
      doe.executeForm(*form);                                                  \
      delete form;                                                             \
    } catch (std::exception & err) {                                           \
      std::cerr << COL_RED "Error: " RESET << err.what() << std::endl;         \
    }                                                                          \
                                                                               \
    std::cout << BOLD COLB_YELLOW "\n" #NAME ":\n - Not Signed:\n" RESET       \
              << std::endl;                                                    \
    try {                                                                      \
      Bureaucrat jhon = Bureaucrat("Jhon", NormalSign);                        \
      Bureaucrat doe = Bureaucrat("Doe", NormalExec);                          \
      AForm *form = new NAME("Bob");                                           \
                                                                               \
      std::cout << *form << std::endl;                                         \
      std::cout << jhon << std::endl;                                          \
      std::cout << doe << std::endl;                                           \
                                                                               \
      doe.executeForm(*form);                                                  \
      delete form;                                                             \
    } catch (std::exception & err) {                                           \
      std::cerr << COL_RED "Error: " RESET << err.what() << std::endl;         \
    }                                                                          \
  }

TEST_FORM(RobotomyRequestForm, 66, 8);
TEST_FORM(PresidentialPardonForm, 21, 1);
TEST_FORM(ShrubberyCreationForm, 71, 55);

int main() {
  test_RobotomyRequestForm();
  test_ShrubberyCreationForm();
  test_PresidentialPardonForm();
};
