/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:27:26 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/11 16:48:02 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <utility>

Span::Span(unsigned int N) : max_capacity(N) {};

Span::~Span() {};

Span::Span(Span& rhs) : std::vector<int>(rhs), max_capacity(rhs.max_capacity) {};

void Span::addNumber(int number)
{
	if (this->size() >= this->max_capacity)
		throw Span::NoMoreCapacity();
	this->push_back(number);
}

int Span::longestSpan()
{
	if (this->size() <= 1)
		throw Span::NotEnougthElements();
	return std::abs(*std::max_element(this->begin(), this->end()) - *std::min_element(this->begin(), this->end()));
}

int Span::shortestSpan()
{
	if (this->size() <= 1)
		throw Span::NotEnougthElements();
	Span copy(*this);
	std::sort(copy.begin(), copy.end());

	int span = std::abs(copy[0] - copy[1]);
	for (unsigned int i = 0; i < copy.size() - 1; i++)
		if (span > std::abs(copy[i] - copy[i + 1]))
			span = std::abs(copy[i] - copy[i + 1]);
	return span;
}

Span::NoMoreCapacity::NoMoreCapacity() {};
Span::NoMoreCapacity::~NoMoreCapacity() throw() {};
const char* Span::NoMoreCapacity::what() const throw()
{
	return "No more capacity in Span";
}

Span::NotEnougthElements::NotEnougthElements() {};
Span::NotEnougthElements::~NotEnougthElements() throw() {};
const char* Span::NotEnougthElements::what() const throw()
{
	return "Not enought elements in Span";
}
