/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:57 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 19:40:28 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cassert>
#include <cstddef>
#include <memory>

template <template <typename Value, typename Allocator = std::allocator<Value> /**/> typename T>
static T<int> merge(T<int> left, T<int> right) {
	T<int>					  sorted_list;
	typename T<int>::iterator lit = left.begin();
	typename T<int>::iterator rit = right.begin();

	while (lit != left.end() && rit != right.end()) {
		if (*lit < *rit)
			sorted_list.push_back(*(lit++));
		else
			sorted_list.push_back(*(rit++));
	}
	sorted_list.insert(sorted_list.end(), lit, left.end());
	sorted_list.insert(sorted_list.end(), rit, right.end());
	return (sorted_list);
}

template <template <typename Value, typename Allocator = std::allocator<Value> /**/> typename T>
static T<int> insertion(T<int> l) {
	assert(!l.empty());
	for (typename T<int>::iterator i = ++(l.begin()); i != l.end(); i++) {
		typename T<int>::value_type key = *i;
		typename T<int>::iterator	j	= --i;
		i++;
		while (j != l.begin() && *j > key) {
			typename T<int>::iterator j_next = ++j;
			*(j_next)						 = *--j;
			j--;
		}
		*(++j) = key;
	}
	return l;
}

template <template <typename Value, typename Allocator = std::allocator<Value> /**/> typename T>
static T<int> wrap(int lhs) {
	T<int> out;
	out.push_back(lhs);
	return (out);
}

template <template <typename Value, typename Allocator = std::allocator<Value> /**/> typename T>
T<int> PMergeMe(T<int> l) {
	std::size_t len = l.size();

	if (len < 10)
		return (insertion(l));

	T<T<int> /**/> pairs;
	for (typename T<int>::iterator i = l.begin(); i != l.end(); i++) {
		typename T<int>::iterator prev = i++;

		if (i != l.end())
			pairs.push_back(merge(wrap<T>(*prev), wrap<T>(*i)));
		else {
			pairs.push_back(wrap<T>(*prev));
			break;	// need to break manually otherwise we get screwed with the +=2
		}
	}

	while (pairs.size() > 1) {
		T<T<int> /**/> new_pairs;

		for (typename T<T<int> /**/>::iterator i = pairs.begin(); i != pairs.end(); i++) {
			typename T<T<int> /**/>::iterator prev = i++;
			if (i != pairs.end())
				new_pairs.push_back(merge(*prev, *i));
			else {
				new_pairs.push_back(*prev);
				break;	// need to break manually otherwise we get screwed with the +=2
			}
		}
		pairs = new_pairs;
	}
	return *pairs.begin();
}

#endif /* PMERGEME_HPP */
