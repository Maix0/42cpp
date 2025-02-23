/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:02:57 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/23 13:45:45 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Some templates have `/**/` in them. this is due to a limitation that requires the `>` to not be right next to eachothers (aka they need
//! whitespace). Due to the formatter that doesn't understant that and remove said whitespace, these comments are inserted to force them not
//! touching...

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
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
void binary_insert(TX& S, X elem, ssize_t end) {
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
	TP pairs;
	for (Xrator it = S.begin(); it != S.end(); it = mv(it, 2)) {
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

	TX			all_groups;
	std::size_t smallers_size = smallers.size();
	std::size_t g_idx		  = 0;
	std::size_t index		  = 0;
	while (index < smallers_size) {
		std::size_t m1_pow_n = (g_idx % 2) ? -1 : 1;
		std::size_t size	 = (((2 << g_idx) - m1_pow_n) / 3) + 1;
		if (size < 2)
			size = 2;
		std::size_t end_idx = std::min(index + size, smallers_size);

		Xrator		start	= mv(smallers.begin(), index);
		Xrator		end		= mv(smallers.begin(), end_idx);

		all_groups.insert(all_groups.end(), std::reverse_iterator<Xrator>(end), std::reverse_iterator<Xrator>(start));
		index += size;
	}

	for (Xrator it = all_groups.begin(); it != all_groups.end(); it++) {
		Xrator bound = std::find(S.begin(), S.end(), *it);
		binary_insert(S, *it, std::distance(S.begin(), bound));
	}

	return S;
}
#endif /* PMERGEME_HPP */
