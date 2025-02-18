/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:49:00 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 19:41:03 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "./PMergeMe.hpp"

int main() {
	int values[] = {
		33, 63, 16, 66, 32, 69, 87, 81, 11, 94, 82, 50, 79, 27, 10, 90, 23, 77, 97, 58, 40, 36, 39, 7,	20,
		98, 14, 17, 62, 64, 91, 18, 35, 96, 10, 86, 47, 68, 1,	60, 38, 76, 12, 61, 72, 31, 49, 8,	75, 34,
		3,	19, 5,	85, 45, 95, 28, 41, 42, 70, 25, 99, 93, 83, 37, 30, 51, 84, 2,	74, 4,	44, 15, 43, 67,
		24, 55, 80, 52, 57, 9,	21, 92, 53, 73, 22, 89, 71, 46, 26, 88, 13, 65, 54, 6,	48, 29, 56, 78, 59,
	};

	std::vector<int> v;
	for (unsigned int i = 0; i < sizeof(values) / sizeof(*values); i++) {
		v.push_back(values[i]);
	}
	for (unsigned int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	v = PMergeMe<std::vector>(v);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}

	std::list<int> l;
	for (unsigned int i = 0; i < sizeof(values) / sizeof(*values); i++) {
		l.push_back(values[i]);
	}
	l = PMergeMe<std::list>(l);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
