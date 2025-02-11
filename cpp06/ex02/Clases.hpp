/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clases.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:52:17 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/24 17:10:14 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASES_HPP
#define CLASES_HPP

#include <iostream>
class Base
{
public:
	virtual ~Base() {};
};

class A : public Base
{
public:
	A() {};
	~A()
	{
		std::cout << "I was a A" << std::endl;
	};
};

class B : public Base
{
public:
	B() {};
	~B()
	{
		std::cout << "I was a B" << std::endl;
	};
};

class C : public Base
{
public:
	C() {};
	~C()
	{
		std::cout << "I was a C" << std::endl;
	};
};

Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

#endif /* CLASES_HPP */
