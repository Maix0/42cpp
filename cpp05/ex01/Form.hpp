/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:37:19 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/02 16:29:32 by maiboyer         ###   ########.fr       */
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

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

#define FGradeException(NAME)                                                  \
  class GradeToo##NAME : public std::exception {                               \
  private:                                                                     \
    std::string message;                                                       \
                                                                               \
  public:                                                                      \
    GradeToo##NAME();                                                          \
    GradeToo##NAME(int grade, std::string reason);                             \
    virtual ~GradeToo##NAME() throw();                                         \
    virtual const char *what() const throw();                                  \
  }

#define FGradeExceptionImpl(NAME, TY)                                          \
  Form::GradeToo##NAME::GradeToo##NAME() {                                     \
    this->message = "Form Grade is too " TY ": no reason given";               \
  }                                                                            \
                                                                               \
  Form::GradeToo##NAME::~GradeToo##NAME() throw(){};                           \
                                                                               \
  Form::GradeToo##NAME::GradeToo##NAME(int grade, std::string reason) {        \
    std::stringstream ss;                                                      \
    ss << "Form Grade is too " TY ": " << grade << ";reason: " << reason;      \
    this->message = ss.str();                                                  \
  }                                                                            \
                                                                               \
  const char *Form::GradeToo##NAME::what() const throw() {                     \
    return (this->message.c_str());                                            \
  }

class Form {
public:
  Form();
  Form(const Form &);
  ~Form(){};
  // Form& operator=(const Form&); // can't write that since there is const
  // members
  Form(std::string name, int sign, int exec);

  FGradeException(High);
  FGradeException(Low);

  const std::string &getName() const;
  const bool &getIsSigned() const;
  const int &getSignGrade() const;
  const int &getExecGrade() const;

  void beSigned(const Bureaucrat &by);

private:
  const std::string name;
  bool is_signed;
  const int signGrade;
  const int execGrade;

  void checkGrades();
};

std::ostream &operator<<(std::ostream &os, Form const &tc);

#endif /* FORM_HPP */
