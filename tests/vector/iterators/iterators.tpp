/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 19:51:49 by phemsi-a         ###   ########.fr       */
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
	
	print_subheading("comparisons");
	ft::vector<int>::iterator it = vector.begin();
	ft::vector<int>::const_iterator const_it = vector.begin();
	ft::vector<int>::reverse_iterator reverse_it = vector.rend();
	ft::vector<int>::const_reverse_iterator const_reverse_it = vector.rend();

	print_instructions("it == const_it");
	std::cout << (it == const_it) << std::endl;
	print_instructions("it == it");
	std::cout << (it == it) << std::endl;
	print_instructions("reverse_it == const_reverse_it");
	std::cout << (reverse_it == const_reverse_it) << std::endl;
	print_instructions("const_it == const_it");
	std::cout << (const_it == const_it) << std::endl;
	print_instructions("it < const_it");
	std::cout << (it < const_it) << std::endl;
	print_instructions("it < it");
	std::cout << (it < it) << std::endl;
	print_instructions("reverse_it < const_reverse_it");
	std::cout << (reverse_it < const_reverse_it) << std::endl;
	print_instructions("const_it < const_it");
	std::cout << (const_it < const_it) << std::endl;
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
