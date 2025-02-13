/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:17:19 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/11 16:31:07 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <exception>
#include <vector>
class Span : public std::vector<int>
{
private:
	const unsigned int max_capacity;

public:
	Span(Span& rhs);
	Span(unsigned int N = 0);
	~Span();

	void addNumber(int number);
	int	 shortestSpan();
	int	 longestSpan();

	template <typename Iterator> void addSpan(Iterator begin, Iterator end)
	{
		for (Iterator i = begin; i != end; i++)
			addNumber(*i);
	}

	class NoMoreCapacity : public std::exception
	{
	public:
		NoMoreCapacity();
		virtual ~NoMoreCapacity() throw();
		virtual const char* what() const throw();
	};

	class NotEnougthElements : public std::exception
	{
	public:
		NotEnougthElements();
		virtual ~NotEnougthElements() throw();
		virtual const char* what() const throw();
	};
};

#endif /* SPAN_HPP */
