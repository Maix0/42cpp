/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:57 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/22 00:20:00 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <memory>

#define TX		 T<X>
#define TP		 T<Pair<X> /**/>
#define Xrator	 typename TX::iterator
#define Prator	 typename TP::iterator
#define TEMPLATE template <template <typename Value, typename Allocator = std::allocator<Value> /**/> class T, typename X>

static std::size_t comparison = 0;

template <typename T>
struct Pair {
	bool single;
	T	 left, right;

	Pair(T l, T r) : single(false), left(l), right(r) {}
	Pair(T l) : single(true), left(l), right(0) {}

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
template <class It>
It mv(It it, std::size_t n = 1) {
	std::advance(it, n);
	return it;
}

template <class It>
std::size_t sum(It begin, It end) {
	std::size_t out = 0;
	for (It it = begin; it != end; it++)
		out += *it;
	return out;
}

TEMPLATE
void binary_insert(TX& S, X elem, std::size_t end) {
	std::size_t left  = 0;
	std::size_t right = end;

	while (left < right) {
		std::size_t mid = left + (right - left) / 2;
		comparison++;
		if (*mv(S.begin(), mid) < elem)
			left = mid + 1;
		else
			right = mid;
	}
	S.insert(mv(S.begin(), left), elem);
}

TEMPLATE
TX merge_insert_sort(TX S) {
	if (S.size() <= 1)
		return S;

	// Step 1: Pair elements arbitrarily
	TP			pairs;
	std::size_t index = 1;
	for (Xrator it = S.begin(); it != S.end(); it++, it++, index++) {
		Xrator next = mv(it);
		if (next == S.end()) {
			pairs.push_back(Pair<X>(*it));
			break;
		}
		pairs.push_back(Pair<X>(*it, *next));
	}

	TX largers, smallers;
	for (Prator it = pairs.begin(); it != pairs.end(); it++) {
		if (!it->single) {
			largers.push_back(it->max());
			smallers.push_back(it->min());
		} else
			smallers.push_back(it->left);
	}

	S = merge_insert_sort(largers);

	{
		Xrator it;
		if ((it = std::find(smallers.begin(), smallers.end(), *S.begin())) != smallers.end()) {
			S.insert(S.begin(), *it);
			smallers.erase(it);
		}
	}

	std::size_t	   smallers_size = smallers.size();
	T<std::size_t> group_size;
	group_size.push_back(2);
	group_size.push_back(2);
	std::size_t groups = 2;
	while (sum(group_size.begin(), group_size.end()) < smallers_size) {
		std::size_t m1_pow_n = (groups % 2) ? -1 : 1;
		group_size.push_back((((2 << groups) - m1_pow_n) / 3) + 1);
		groups++;
	}

	TX all_groups;

	index = 0;
	for (typename T<std::size_t>::iterator size = group_size.begin(); size != group_size.end(); size++) {
		if (index >= smallers_size)
			break;
		std::size_t end_idx	 = std::min(index + *size, smallers_size);

		Xrator		start	 = mv(smallers.begin(), index);
		Xrator		end		 = mv(smallers.begin(), end_idx);
		index				+= *size;

		TX group(start, end);
		std::reverse(group.begin(), group.end());

		all_groups.insert(all_groups.end(), group.begin(), group.end());
	}

	for (Xrator it = all_groups.begin(); it != all_groups.end(); it++) {
		Xrator bound = std::find(S.begin(), S.end(), *it);

		binary_insert(S, *it, std::distance(S.begin(), bound));
	}

	return S;
}
#endif /* PMERGEME_HPP */
