/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:18:14 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/14 22:17:15 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>

class Value {
public:
	enum Type {
		OPERATOR,
		NUMBER,
	};

	Type type;
	union {
		long val;
		char op;
	};

	Value();
	~Value();
	Value(long val);
	Value(char op);
	Value(const Value& rhs);
};

class RPN {
	// basically only static method allowed here
private:
	RPN();
	~RPN();
	RPN(const RPN& rhs);
	RPN& operator=(const RPN& rhs);

public:
	static long compute(const std::string& s);

	class InvalidChar : public std::exception {
		virtual const char* what() const throw();
	};
	class MissingOperand : public std::exception {
		virtual const char* what() const throw();
	};
	class MissingOperator : public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidOperator : public std::exception {
		virtual const char* what() const throw();
	};
	class InvalidOperand : public std::exception {
		virtual const char* what() const throw();
	};
	class DivisionByZero : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif /* RPN_HPP */
