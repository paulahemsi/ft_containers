/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:40:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 19:02:42 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"
#include "iterators.tpp"

void test_iterators(void)
{
	print_title("ITERATORS");
	iterate_through_vector();
	iterate_through_vector_changing_values();
	compare_iterators_of_same_vector<ft::vector<int>::iterator>();
	compare_iterators_of_different_vector<ft::vector<int>::iterator>();
	compare_iterator_when_change_element_value<ft::vector<int>::iterator>(0, 2);
}