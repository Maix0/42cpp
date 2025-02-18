/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:57 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/18 22:22:08 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cassert>
#include <cstddef>
#include <iterator>
#include <memory>

/// copy the iterator and advance it by n elements
template <class InputIt>
InputIt advance(InputIt it, int n = 1) {
	std::advance(it, n);
	return it;
}

#define Titerator typename T<int>::iterator
#define TT		  T<T<int> >
#define BTEMPLATE template <template <typename Value, typename Allocator = std::allocator<Value> > class T>

BTEMPLATE
static T<int> merge(T<int> left, T<int> right) {
	T<int>	  sorted_list;
	Titerator lit = left.begin();
	Titerator rit = right.begin();

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

BTEMPLATE
static T<int> insertion(T<int> l) {
	assert(!l.empty());
	for (Titerator i = advance(l.begin()); i != l.end(); i++) {
		int		  key = *i;
		Titerator j	  = advance(i, -1);
		while (std::distance(j, l.begin()) >= 0 && *j > key) {
			*advance(j) = *j;
			j--;
		}
		*advance(j) = key;
	}
	return l;
}

BTEMPLATE
static T<int> w(int lhs) {
	T<int> out;
	out.push_back(lhs);
	return (out);
}

BTEMPLATE
T<int> PMergeMe(T<int> l) {
	std::size_t len = l.size();

	if (len < 10)
		return (insertion(l));

	TT pairs;
	for (Titerator i = l.begin(); i != l.end(); i = advance(i, 2)) {
		if (advance(i) != l.end())
			pairs.push_back(merge(w<T>(*i), w<T>(*advance(i))));
		else {
			pairs.push_back(w<T>(*i));
			break;	// need to break manually otherwise we get screwed with the +=2
		}
	}

	while (pairs.size() > 1) {
		TT new_pairs;

		for (typename TT::iterator i = pairs.begin(); i != pairs.end(); i = advance(i, 2)) {
			if (advance(i) != pairs.end())
				new_pairs.push_back(merge(*i, *advance(i)));
			else {
				new_pairs.push_back(*i);
				break;	// need to break manually otherwise we get screwed with the +=2
			}
		}
		pairs = new_pairs;
	}
	return *pairs.begin();
}

#endif /* PMERGEME_HPP */
