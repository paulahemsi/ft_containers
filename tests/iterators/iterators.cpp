/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:40:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 21:50:31 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.tpp"

void test_const_reverse_iterators(void)
{
	print_title("CONST REVERSE ITERATORS");
	// iterate_through_vector<ft::vector<int>::const_reverse_iterator>();
	// compare_iterators_of_same_vector<ft::vector<int>::const_reverse_iterator>();
	// compare_iterators_of_different_vector<ft::vector<int>::const_reverse_iterator>();
	// compare_iterator_when_change_element_value<ft::vector<int>::const_reverse_iterator>(7, 5);
}

void test_reverse_iterators(void)
{
	print_title("REVERSE ITERATORS");
	iterate_through_vector<ft::vector<int>::reverse_iterator>();
	iterate_through_vector_changing_values<ft::vector<int>::reverse_iterator>();
	compare_iterators_of_same_vector<ft::vector<int>::reverse_iterator>();
	compare_iterators_of_different_vector<ft::vector<int>::reverse_iterator>();
	compare_iterator_when_change_element_value<ft::vector<int>::reverse_iterator>(7, 5);
}

void test_const_iterators(void)
{
	print_title("CONST ITERATORS");
	iterate_through_vector<ft::vector<int>::const_iterator>();
	compare_iterators_of_same_vector<ft::vector<int>::const_iterator>();
	compare_iterators_of_different_vector<ft::vector<int>::const_iterator>();
	compare_iterator_when_change_element_value<ft::vector<int>::const_iterator>(0, 2);
}

void test_iterators(void)
{
	print_title("ITERATORS");
	iterate_through_vector<ft::vector<int>::iterator>();
	iterate_through_vector_changing_values<ft::vector<int>::iterator>();
	compare_iterators_of_same_vector<ft::vector<int>::iterator>();
	compare_iterators_of_different_vector<ft::vector<int>::iterator>();
	compare_iterator_when_change_element_value<ft::vector<int>::iterator>(0, 2);
}