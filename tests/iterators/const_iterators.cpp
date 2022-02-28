/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:10 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/28 17:53:40 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

static void iterate_through_vector(void)
{
	print_subheading("Iterate through vector");
	
	ft::vector<int> vector;
	
	for (int i=1; i<=5; i++)
		vector.push_back(i);

	for (ft::vector<int>::const_iterator it = vector.begin() ; it != vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;	
}

void test_const_iterators(void)
{
	print_title("CONST ITERATORS");
	iterate_through_vector();
	iterators_of_same_vector<ft::vector<int>::const_iterator>();
	iterators_of_differents_vector<ft::vector<int>::const_iterator>();
	iterator_when_change_value<ft::vector<int>::const_iterator>();
}
