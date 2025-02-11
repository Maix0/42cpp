/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:40:57 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/10 17:13:50 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <cstdlib>
template <typename T> class Array
{
public:
	class IndexOutOfBound : public std::exception
	{
	public:
		IndexOutOfBound() {};
		virtual ~IndexOutOfBound() throw() {};
		virtual const char* what() const throw()
		{
			return "index out of bound";
		};
	};

	Array()
	{
		this->length = 1;
		this->buffer = new T();
	};
	Array(unsigned int N)
	{
		this->length = N;
		if (N > 1)
			this->buffer = new T[N];
		else if (N == 1)
			this->buffer = new T();
		else
			this->buffer = NULL;
	}
	~Array()
	{
		if (this->length > 1)
			delete[] this->buffer;
		else if (this->length == 1)
			delete this->buffer;
	}

	T& operator[](std::size_t i)
	{
		if (i >= this->length)
			throw IndexOutOfBound();

		return (this->buffer[i]);
	}

	const T& operator[](std::size_t i) const
	{
		if (i >= this->length)
			throw IndexOutOfBound();

		return (this->buffer[i]);
	}

	Array& operator=(const Array& rhs)
	{
		if (this == &rhs)
			return (rhs);
		this->length = rhs.length;
		if (this->length > 1)
			this->buffer = new T[this->length];
		else if (this->length == 1)
			this->buffer = new T();
		else
			this->buffer = NULL;

		for (std::size_t i = 0; i < this->length; i++)
			this->buffer[i] = rhs.buffer[i];

		return (*this);
	}

	Array(const Array& rhs)
	{
		this->length = rhs.length;
		if (this->length > 1)
			this->buffer = new T[this->length];
		else if (this->length == 1)
			this->buffer = new T();
		else
			this->buffer = NULL;

		for (std::size_t i = 0; i < this->length; i++)
			this->buffer[i] = rhs.buffer[i];
	}

	unsigned int size()
	{
		return (this->length);
	}

private:
	T*			 buffer;
	unsigned int length;
};

#endif /* ARRAY_HPP */
