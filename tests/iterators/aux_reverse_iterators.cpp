/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_reverse_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:42:27 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/28 22:10:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

static void	reverse_iterate_vector_changing_value(ft::vector<int>& vector)
{
	int i = 0;
	for (ft::vector<int>::reverse_iterator it = vector.rbegin() ; it != vector.rend(); ++it)
		*it *= i++;
}

static void	reverse_iterate_vector_printing(ft::vector<int>& vector)
{
	for (ft::vector<int>::reverse_iterator it = vector.rbegin() ; it != vector.rend(); ++it)
	// for (ft::vector<int>::const_reverse_iterator it = vector.rbegin() ; it != vector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void reverse_iterate_through_vector_changing_values(void)
{
	print_subheading("Iterate reversely through vector changing values");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	reverse_iterate_vector_changing_value(vector);
	reverse_iterate_vector_printing(vector);
}

void reverse_iterate_through_vector(void)
{
	print_subheading("Iterate reversely through vector");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	reverse_iterate_vector_printing(vector);
}