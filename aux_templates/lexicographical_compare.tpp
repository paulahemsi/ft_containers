/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:42:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/18 22:00:52 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXIXOGRAPHICAL_COMPARE_TPP
#define LEXIXOGRAPHICAL_COMPARE_TPP

#include <iostream>

namespace ft
{
	/*
	* A lexicographical comparison is the kind of comparison generally used to sort words
	* alphabetically in dictionaries; It involves comparing sequentially the elements that have the 
	* same position in both ranges against each other until one element is not equivalent to the 
	* other. The result of comparing these first non-matching elements is the result of the 
	* lexicographical comparison.
	* return value: true if the first range compares lexicographically less than the second. false otherwise (including when all the elements of both ranges are equivalent).
	*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1; ++first2;
		}
		if (first2 != last2)
			return (true);
		return (false);
	}

	/*
	* Compares the elements in the range [first1,last1) with those in the range beginning at first2,
	* and returns true if all of the elements in both ranges match.
	*/
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
}

#endif
