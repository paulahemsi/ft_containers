/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:40:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/28 17:58:21 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

static void iterate_through_vector_changing_values(void)
{
	print_subheading("Iterate through vector changing values");
	
	ft::vector<int> vector;
	
	for (int i=1; i<=5; i++)
		vector.push_back(i);

	for (ft::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it)
		*it *= 2;
	for (ft::vector<int>::const_iterator it = vector.begin() ; it != vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;	
}

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

void test_iterators(void)
{
	print_title("ITERATORS");
	iterate_through_vector();
	iterate_through_vector_changing_values();
	iterators_of_same_vector<ft::vector<int>::iterator>();
	iterators_of_differents_vector<ft::vector<int>::iterator>();
	iterator_when_change_value<ft::vector<int>::iterator>();
}