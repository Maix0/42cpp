/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:49:00 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 23:11:50 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>
#include "./PMergeMe.hpp"

template <typename Iterator>
bool is_sorted(Iterator begin, Iterator end) {
	for (Iterator i = begin; i != end; i++) {
		Iterator next = advance(i, 1);
		if (next != end && *i > *next)
			return false;
	}
	return true;
}

#define START_TIMER before = std::clock();
#define END_TIMER(MSG)    \
	after = std::clock(); \
	std::cout << MSG << " took " << ((double)(after - before) * 1000000.0) / (double)(CLOCKS_PER_SEC) << "us to do !" << std::endl;

template <typename C>
void print_container(const C& c, const std::string& type, const std::string& name, int max = 50) {
	int count = 0;
	std::cout << type << " " << name << " = [";
	typename C::const_iterator it = c.begin();
	if (it != c.end()) {
		std::cout << *it;
		count++;
	}
	for (; it != c.end(); it++) {
		std::cout << ", " << *it;
		if (++count >= max) {
			std::cout << ", ... ";
			break;
		}
	}
	std::cout << "]" << std::endl << std::endl;
}

template <typename C>
void do_test(int values[], size_t size, std::string name) {
	C			 unsorted;

	// such that the variable are declared now :)
	std::clock_t before;
	std::clock_t after;

	START_TIMER;
	for (unsigned int i = 0; i < size; i++)
		unsorted.push_back(values[i]);
	END_TIMER("pushing " << size << " elements into " << name);

	print_container(unsorted, "unsorted", name);

	START_TIMER;
	C sorted = PMergeMe(unsorted);
	END_TIMER("sorting " << size << " elements using " << name);

	print_container(sorted, "sorted", name);

	if (is_sorted<typename C::iterator>(sorted.begin(), sorted.end()))
		std::cout << name << " is indeed sorted !" << std::endl;
	else
		std::cout << name << " is NOT sorted !" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
}

#define NB 10000
int values[NB] = {0};

int main() {
	std::srand(std::time(NULL));
	for (int i = 0; i < NB; i++)
		values[i] = std::rand() % (3 * NB);

	do_test<std::vector<int> /**/>(values, sizeof(values) / sizeof(values[0]), "std::vector");
	do_test<std::list<int> /**/>(values, sizeof(values) / sizeof(values[0]), "std::list");
}
