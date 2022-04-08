/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/08 17:45:48 by lfrasson         ###   ########.fr       */
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
ft::map<int, int>		create_map_of_random_integers(int size, int seed);
ft::map<float, float>	create_map_of_floats(int size);
void print_found(ft::map<float, float>::const_iterator it, ft::map<float, float>::const_iterator end);

#endif
