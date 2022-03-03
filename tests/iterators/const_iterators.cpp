/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:10 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 19:02:59 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

void test_const_iterators(void)
{
	print_title("CONST ITERATORS");
	iterate_through_vector();
	compare_iterators_of_same_vector<ft::vector<int>::const_iterator>();
	compare_iterators_of_different_vector<ft::vector<int>::const_iterator>();
	compare_iterator_when_change_element_value<ft::vector<int>::const_iterator>(0, 2);
}