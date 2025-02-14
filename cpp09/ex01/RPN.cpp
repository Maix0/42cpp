/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:18:10 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/14 22:19:07 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <ios>
#include <iostream>
#include <string>

#define IMPL_ERR(NAME, MSG)                  \
	const char* NAME::what() const throw() { \
		return MSG;                          \
	};

IMPL_ERR(RPN::DivisionByZero, "division by zero occured");
IMPL_ERR(RPN::InvalidChar, "invalid char in rpn expression");
IMPL_ERR(RPN::InvalidOperand, "got an invalid operand");
IMPL_ERR(RPN::InvalidOperator, "got an invalid operator");
IMPL_ERR(RPN::MissingOperator, "missing operator due to too many operand left");
IMPL_ERR(RPN::MissingOperand, "missing operand for operation");

Value::Value() : type(Value::NUMBER), val(0) {};
Value::Value(long nb) : type(Value::NUMBER), val(nb) {};
Value::Value(char op) : type(Value::OPERATOR), op(op) {};
Value::~Value() {};
Value::Value(const Value& rhs) : type(rhs.type) {
	if (this->type == Value::NUMBER)
		this->val = rhs.val;
	else
		this->op = rhs.op;
};

RPN::RPN() {};
RPN::~RPN() {};
RPN::RPN(const RPN& _) {};
RPN& RPN::operator=(const RPN& _) {
	return (*this);
}

long RPN::compute(const std::string& s) {
	std::stack<Value> stack;
	for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
		if (std::isspace(*it))
			continue;
		if (std::isdigit(*it)) {
			stack.push(Value((long)(*it - '0')));
			continue;
		}
		Value c = Value((char)*it);
		if (stack.size() < 2)
			throw RPN::MissingOperand();

		Value op0 = stack.top();
		stack.pop();
		Value op1 = stack.top();
		stack.pop();

		if (op0.type == Value::OPERATOR || op1.type == Value::OPERATOR)
			throw RPN::InvalidOperand();

		long val = 0;
		switch (c.op) {
			case '+':
				val = op1.val + op0.val;
				break;
			case '*':
				val = op1.val * op0.val;
				break;
			case '-':
				val = op1.val - op0.val;
				break;
			case '/':
				if (op0.val == 0)
					throw RPN::DivisionByZero();
				val = op1.val / op0.val;
				break;
			default:
				throw RPN::InvalidOperator();
		}
		stack.push(Value(val));
	}
	if (stack.empty())
		throw RPN::MissingOperand();
	if (stack.size() > 1)
		throw RPN::MissingOperator();
	Value ret = stack.top();

	if (ret.type == Value::OPERATOR)
		throw RPN::InvalidOperand();
	return (ret.val);
}
