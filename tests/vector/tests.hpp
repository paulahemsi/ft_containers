/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/22 15:54:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# include <stdlib.h>
# include <algorithm>
# include "auxiliary.hpp"

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <vector>
#else
	#define VERSION "FT_VERSION"
	#include <vector.hpp>
#endif

template <typename T>
void displayVector(const ft::vector<T>& vector_)
{
	std::cout << "vector capacity: " << vector_.capacity() << " vector max size: " << vector_.max_size() << std::endl;
	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
	std::cout << YELLOW << "vector: " << std::endl;
	for (typename ft::vector<T>::const_iterator element = vector_.begin(); element != vector_.end(); ++element )
		std::cout << *element << ' ';
	std::cout << std::endl << RESET << std::endl;
}

ft::vector<int>	create_vector_of_random_integers(int size, int seed);

void test_constructors(void);
void test_simple_assignment_operator(void);
void test_iterators(void);
void test_const_iterators(void);
void test_reverse_iterators(void);
void test_const_reverse_iterators(void);
void test_out_of_bounds(void);
void test_relational_operators(void);
void test_empty(void);
void test_assign(void);
void test_clear(void);
void test_data(void);
void test_erase(void);
void test_insert(void);
void test_swap(void);
void test_resize(void);
void test_reserve(void);
void test_get_allocator(void);
void test_at_front_back_and_dereference(void);
ft::vector<int> test_push_back(void);
void test_pop_back(ft::vector<int> integers);

#endif
