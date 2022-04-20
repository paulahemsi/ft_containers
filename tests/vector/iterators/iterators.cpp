/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:40:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 21:48:03 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.tpp"

void test_const_reverse_iterators(void)
{
	print_title("CONST REVERSE ITERATORS");
	// iterate_through_vector<ft::vector<int>::const_reverse_iterator>();
}

void test_reverse_iterators(void)
{
	print_title("REVERSE ITERATORS");
	iterate_through_vector<ft::vector<int>::reverse_iterator>();
	iterate_through_vector_changing_values<ft::vector<int>::reverse_iterator>();
}

void test_const_iterators(void)
{
	print_title("CONST ITERATORS");
	iterate_through_vector<ft::vector<int>::const_iterator>();
}

void test_iterators(void)
{
	print_title("ITERATORS");
	iterate_through_vector<ft::vector<int>::iterator>();
	iterate_through_vector_changing_values<ft::vector<int>::iterator>();
}