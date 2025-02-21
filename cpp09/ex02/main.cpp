/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:49:00 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/22 00:26:12 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>
#include "./PMergeMe.hpp"

template <typename Iterator>
bool is_sorted(Iterator begin, Iterator end) {
	for (Iterator i = begin; i != end; i++) {
		Iterator next = mv(i, 1);
		if (next != end && *i > *next)
			return false;
	}
	return true;
}

#define NB 3000
int				   values[NB]	  = {0};
unsigned long long comparison_max = 0;

#define START_TIMER before = std::clock();
#define END_TIMER(MSG)                                                             \
	after = std::clock();                                                          \
	std::cout << MSG                                                               \
			  << " took "                                                          \
				 "\x1b[33m"                                                        \
			  << ((double)(after - before) * 1000000.0) / (double)(CLOCKS_PER_SEC) \
			  << "\x1b[0m"                                                         \
				 "us to do !"                                                      \
			  << std::endl;

template <typename It>
const char* col(It it) {
	if (*mv(it, -1) > *it)
		return ("\x1b[31m");
	return ("");
}

template <typename C>
void print_container(const C& c, const std::string& type, const std::string& name, int max = 50) {
	int count = 0;
	std::cout << type << " " << name << " = [";
	typename C::const_iterator it = c.begin();
	if (it != c.end()) {
		std::cout << *it;
		count++;
		it++;
	}
	bool clipped = false;
	for (; it != c.end(); it++) {
		std::cout << ", " << col(it) << *it << "\x1b[0m";
		if (++count >= max && mv(it) != c.end()) {
			std::cout << ", ... ";
			clipped = true;
			break;
		}
	}
	std::cout << "]";
	if (clipped)
		std::cout << " (clipped at " << max << " elements)";

	std::cout << std::endl << std::endl;
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
	END_TIMER(
		"\x1b[36m"
		"Pushing "
		"\x1b[34m"
		<< size
		<< "\x1b[0m"
		   " elements into "
		<< name);

	print_container(unsorted, name, "unsorted");

	START_TIMER;
	C sorted = merge_insert_sort(unsorted);
	END_TIMER(
		"\x1b[35m"
		"Sorting "
		"\x1b[34m"
		<< size
		<< "\x1b[0m"
		   " elements using "
		<< name);

	print_container(sorted, name, "sorted");

	std::cout << comparison << " for a list of " << sorted.size() << " (theoritical max is " << comparison_max << ")" << std::endl;
	if (is_sorted<typename C::iterator>(sorted.begin(), sorted.end()))
		std::cout << "\x1b[32m" << name << " is indeed sorted !" << "\x1b[0m" << std::endl;
	else
		std::cout << "\x1b[31m" << name << " is NOT sorted !" << "\x1b[0m" << std::endl;

	comparison = 0;
	std::cout << std::endl;
	std::cout << std::endl;
}

// main function that launches tests
int main() {
	int nb_values = NB;

	std::srand(std::time(NULL));
	for (int i = 0; i < nb_values; i++) {
		values[i]		= std::rand() % (3 * nb_values);
		comparison_max += (unsigned int)std::ceil(log2f(3. * (double)(i + 1) / 4.));
	}

	do_test<std::vector<int> /**/>(values, sizeof(values) / sizeof(values[0]), "std::vector");
	do_test<std::list<int> /**/>(values, sizeof(values) / sizeof(values[0]), "std::list");
}
