/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:21:10 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/02 16:28:46 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef COLORS_H
#define COLORS_H

#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define WEAK "\x1b[2m"
#define ITALIC "\x1b[3m"
#define UNDERLINE "\x1b[4m"

#define COL_BLACK "\x1b[30m"
#define COL_RED "\x1b[31m"
#define COL_GREEN "\x1b[32m"
#define COL_YELLOW "\x1b[33m"
#define COL_BLUE "\x1b[34m"
#define COL_MAGENTA "\x1b[35m"
#define COL_CYAN "\x1b[36m"
#define COL_WHITE "\x1b[37m"

#define COLB_BLACK "\x1b[90m"
#define COLB_RED "\x1b[91m"
#define COLB_GREEN "\x1b[92m"
#define COLB_YELLOW "\x1b[93m"
#define COLB_BLUE "\x1b[94m"
#define COLB_MAGENTA "\x1b[95m"
#define COLB_CYAN "\x1b[96m"
#define COLB_WHITE "\x1b[97m"

#define COLBG_BLACK "\x1b[40m"
#define COLBG_RED "\x1b[41m"
#define COLBG_GREEN "\x1b[42m"
#define COLBG_YELLOW "\x1b[43m"
#define COLBG_BLUE "\x1b[44m"
#define COLBG_MAGENTA "\x1b[45m"
#define COLBG_CYAN "\x1b[46m"
#define COLBG_WHITE "\x1b[47m"

#define COLBBG_BLACK "\x1b[10m0"
#define COLBBG_RED "\x1b[10m1"
#define COLBBG_GREEN "\x1b[10m2"
#define COLBBG_YELLOW "\x1b[10m3"
#define COLBBG_BLUE "\x1b[10m4"
#define COLBBG_MAGENTA "\x1b[10m5"
#define COLBBG_CYAN "\x1b[10m6"
#define COLBBG_WHITE "\x1b[10m7"

#endif /* COLORS_H */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class AForm;

#include <exception>
#include <sstream>
#include <string>

#define BGradeException(NAME)                                                  \
  class GradeToo##NAME : public std::exception {                               \
  private:                                                                     \
    std::string message;                                                       \
                                                                               \
  public:                                                                      \
    GradeToo##NAME();                                                          \
    GradeToo##NAME(int grade);                                                 \
    virtual ~GradeToo##NAME() throw();                                         \
    virtual const char *what() const throw();                                  \
  }

#define BGradeExceptionImpl(NAME, TY)                                          \
  Bureaucrat::GradeToo##NAME::GradeToo##NAME() {                               \
    this->message = "Bureaucrat Grade is too " TY;                             \
  }                                                                            \
                                                                               \
  Bureaucrat::GradeToo##NAME::~GradeToo##NAME() throw(){};                     \
                                                                               \
  Bureaucrat::GradeToo##NAME::GradeToo##NAME(int grade) {                      \
    std::stringstream ss;                                                      \
    ss << "Bureaucrat Grade is too " TY ": " << grade;                         \
    this->message = ss.str();                                                  \
  }                                                                            \
                                                                               \
  const char *Bureaucrat::GradeToo##NAME::what() const throw() {               \
    return (this->message.c_str());                                            \
  }

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &);

  Bureaucrat(std::string name);
  Bureaucrat(std::string name, int grade);

  const int &getGrade() const;
  const std::string &getName() const;

  void executeForm(AForm const &form);

  BGradeException(High);
  BGradeException(Low);

  void increaseGrade();
  void decreaseGrade();

  void signForm(AForm &form);

private:
  const std::string name;
  int grade;

  static void checkGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &tc);

#endif /* BUREAUCRAT_HPP */
