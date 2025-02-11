/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:37 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/10 15:41:05 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::cout << "\nstd::vector<int>" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 15; i++)
	{
		v.push_back(i * i);
	}
	easyfind(v, 5 * 5);
	easyfind(v, 24);
	easyfind(v, -9);
	easyfind(v, 9);


	std::cout << "\nstd::list<int>" << std::endl;
	std::list<int> l;
	for (int i = 0; i < 15; i++)
	{
		l.push_front(i * i);
	}
	easyfind(l, 5 * 5);
	easyfind(l, 24);
	easyfind(l, -9);
	easyfind(l, 9);

	std::cout << "\nstd::deque<int>" << std::endl;
	std::deque<int> d;
	for (int i = 0; i < 15; i++)
	{
		if (i % 2)
			d.push_front(i * i);
		else
			d.push_back(-(i * i));
	}
	easyfind(d, 5 * 5);
	easyfind(d, -25);
	easyfind(d, -9);
	easyfind(d, 9);
}
