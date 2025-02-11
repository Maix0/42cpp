/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:52:08 by maiboyer          #+#    #+#             */
/*   Updated: 2024/12/24 17:09:23 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Clases.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base* generate(void)
{
	int	  r = std::rand() % 3;
	Base* ptr = NULL;

	if (r == 0)
		ptr = new A();
	else if (r == 1)
		ptr = new B();
	else
		ptr = new C();

	return (ptr);
}
void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "p was an A (ptr)" << std::endl;
	if (b != NULL)
		std::cout << "p was an B (ptr)" << std::endl;
	if (c != NULL)
		std::cout << "p was an C (ptr)" << std::endl;
}
void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "p was an A (ref)" << std::endl;
		(void)(a);
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "p was an B (ref)" << std::endl;
		(void)(b);
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "p was an C (ref)" << std::endl;
		(void)(c);
	}
	catch (const std::exception& e)
	{
	}
}

int main(int argc, char** argv)
{
	if (argc == 2 && argv[1][1] == '\0')
	{
		if (argv[1][0] == 'A')
		{
			A val;
			identify(val);
			identify(&val);
		}
		else if (argv[1][0] == 'B')
		{
			B val;
			identify(val);
			identify(&val);
		}
		else if (argv[1][0] == 'C')
		{
			C val;
			identify(val);
			identify(&val);
		}
		else
			std::cerr << "Unknown type: " << argv[1] << std::endl;
	}
	else
	{
		std::cout << "Generating a random type" << std::endl;

		Base* val = generate();
		identify(*val);
		identify(val);
		delete val;
	}
}
