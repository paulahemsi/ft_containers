/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:10 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/28 21:32:42 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

void test_const_iterators(void)
{
	print_title("CONST ITERATORS");
	iterate_through_vector();
	iterators_of_same_vector<ft::vector<int>::const_iterator>();
	iterators_of_differents_vector<ft::vector<int>::const_iterator>();
	iterator_when_change_value<ft::vector<int>::const_iterator>();
}