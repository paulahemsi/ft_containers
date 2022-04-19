/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <iostream>
#include "Map.hpp"
#include "auxiliary.hpp"

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <map>
#else
	#define VERSION "FT_VERSION"
	#include "pair.tpp"
#endif

void test_pair(void);
void test_find(void);
void test_get_allocator(void);
void test_insert(void);
void test_erase(void);
void test_access_element_operator(void);
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
ft::map<int, int>		create_map_of_random_integers(int size, int seed);
ft::map<float, float>	create_map_of_floats(int size);
void print_found(ft::map<float, float>::const_iterator it, ft::map<float, float>::const_iterator end);

template<class key, class value>
void print_map( const ft::map<key, value> &map)
{
	typename ft::map<key, value>::const_iterator	it;

	for (it = map.begin(); it != map.end(); ++it) {
 	   std::cout << it->first << ", " << it->second << std::endl;
	}
	std::cout << std::endl;
}
#endif
