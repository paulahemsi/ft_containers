/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 21:47:34 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TPP
# define ITERATORS_TPP

#include "iterators.hpp"

template<typename T>
static void	iterate_vector_printing(ft::vector<int>& vector)
{
	T	it;
	T	end;

	getBegin(vector, it);
	getEnd(vector, end);
	while(it != end)
		std::cout << ' ' << *it++;
	std::cout << std::endl;
}

template<typename T>
void iterate_through_vector(void)
{
	print_subheading("Iterate through vector");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	iterate_vector_printing<T>(vector);
}

template<typename T>
static void	iterate_vector_changing_value(ft::vector<int>& vector)
{
	T	it;
	T	end;

	getBegin(vector, it);
	getEnd(vector, end);
	int i = 0;
	while (it != end)
		*it++ *= i++;
}

template<typename T>
void iterate_through_vector_changing_values(void)
{
	print_subheading("Iterate through vector changing values");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	iterate_vector_changing_value<T>(vector);
	iterate_vector_printing<T>(vector);
}

#endif