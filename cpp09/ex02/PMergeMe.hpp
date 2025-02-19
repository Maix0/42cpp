/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:57 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/19 17:40:04 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>

template <typename T>
struct Pair {
	bool single;
	T	 left, right;

	Pair(T l, T r) {
		single = false;
		left   = l;
		right  = r;
	}

	Pair(T l) {
		single = true;
		left   = l;
		right  = 0;
	}

	T max() {
		if (single)
			return left;
		if (left < right)
			return right;
		return left;
	}

	T min() {
		if (single)
			return left;
		if (left > right)
			return right;
		return left;
	}
};

/// copy the iterator and advance it by n elements
template <class InputIt>
InputIt advance(InputIt it, int n = 1) {
	std::advance(it, n);
	return it;
}

template <class InputIt>
std::size_t sum(InputIt begin, InputIt end) {
	std::size_t out = 0;
	for (InputIt it = begin; it != end; it++)
		out += *it;
	return out;
}

#define Titerator typename T<int>::iterator
#define Tint	  T<int>
#define TT		  T<Pair<int> >
#define TTrator	  typename T<Pair<int> >::iterator
#define BTEMPLATE template <template <typename Value, typename Allocator = std::allocator<Value> > class T>

static unsigned long long comparison = 0;

BTEMPLATE
void binary_insert(Tint& S, int elem) {
	int left  = 0;
	int right = S.size();

	while (left < right) {
		int mid		= left + (right - left) / 2;
		comparison += 1;
		if (*advance(S.begin(), mid) < elem)
			left = mid + 1;
		else
			right = mid;
	}
	S.insert(advance(S.begin(), left), elem);
}

BTEMPLATE Tint merge_insert_sort(Tint S) {
	if (S.size() <= 1)
		return S;

	// Step 1: Pair elements arbitrarily
	TT pairs;
	for (Titerator it = S.begin(); it != S.end(); it++, it++) {
		Titerator next = advance(it);
		if (next == S.end()) {
			pairs.push_back(Pair<int>(*it));
			break;
		}
		pairs.push_back(Pair<int>(*it, *next));
	}

	// Step 2: Compare each pair and keep the larger element
	Tint largers, smallers;
	for (TTrator it = pairs.begin(); it != pairs.end(); it++) {
		if (!it->single) {
			largers.push_back(it->max());
			smallers.push_back(it->min());
		} else
			largers.push_back(it->left);
	}

	S = merge_insert_sort(largers);

	if (!smallers.empty() and !S.empty()) {
		Titerator	min_value = std::min_element(largers.begin(), largers.end());
		std::size_t min_idx	  = std::distance(largers.begin(), min_value);

		if (min_idx < smallers.size()) {
			Titerator eiter	  = advance(smallers.begin(), min_idx);
			int		  element = *eiter;
			smallers.erase(eiter);

			S.insert(S.begin(), element);
		}
	}

	Tint group_sizes;
	group_sizes.push_back(2);
	group_sizes.push_back(2);

	while (sum(group_sizes.begin(), group_sizes.end()) < smallers.size()) {
		int n_1 = *advance(group_sizes.end(), -1);
		int n_2 = *advance(group_sizes.end(), -2);
		group_sizes.push_back(2 * n_2 + n_1);
	}

	std::size_t index = 0;
	Tint		ordered_remaining;
	for (Titerator size = group_sizes.begin(); size != group_sizes.end(); size++) {
		if (index >= smallers.size())
			break;

		if (index + *size >= smallers.size())
			*size = smallers.size() - index;
		Titerator start = advance(smallers.begin(), index);
		Titerator end	= advance(start, *size);
		Tint	  group(start, end);

		std::reverse(group.begin(), group.end());
		ordered_remaining.insert(ordered_remaining.end(), group.begin(), group.end());
		index += *size;
	}
	for (Titerator it = ordered_remaining.begin(); it != ordered_remaining.end(); it++)
		binary_insert(S, *it);
	return S;
}
#endif /* PMERGEME_HPP */
