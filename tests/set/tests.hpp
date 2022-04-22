/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/22 15:54:04 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <iostream>
#include <set.hpp>
#include "auxiliary.hpp"

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <set>
#else
	#define VERSION "FT_VERSION"
#endif

void test_pair(void);
void test_find(void);
void test_get_allocator(void);
void test_insert(void);
void test_erase(void);
void test_size(void);
void test_lower_bound(void);
void test_upper_bound(void);
void test_equal_range(void);
void test_count(void);
void test_constructors(void);
void test_assigment_operator(void);
void test_empty(void);
void test_value_comp(void);
void max_size(void);
void test_swap(void);
void test_equality_operator(void);
void test_iterators(void);
void less_than_comparison(void);
ft::set<int>	create_set_of_random_integers(int size, int seed);
ft::set<float>	create_set_of_floats(int size);
void print_found(ft::set<float>::const_iterator it, ft::set<float>::const_iterator end);

template<class value>
void print_set( const ft::set<value> &set)
{
	typename ft::set<value>::const_iterator	it;

	for (it = set.begin(); it != set.end(); ++it) {
 	   std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}
#endif
