/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterators.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:54:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 16:57:57 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

void test_const_reverse_iterators(void)
{
	print_title("CONST REVERSE ITERATORS");
	reverse_iterate_through_vector();
	reverse_iterate_through_vector_changing_values();
	// compare_reverse_iterators_of_same_vector<ft::vector<int>::const_reverse_iterator>();
	// compare_reverse_iterators_of_different_vector<ft::vector<int>::const_reverse_iterator>();
	// compare_reverse_iterator_when_change_element_value<ft::vector<int>::const_reverse_iterator>();
}