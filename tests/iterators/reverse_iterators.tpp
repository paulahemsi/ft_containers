/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:59:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 16:55:43 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATORS_TPP
# define REVERSE_ITERATORS_TPP

#include "iterators.hpp"

template<typename T>
static void	compare_reverse_iterators_of_same_vector(void)
{
	print_subheading("Iterators of the same vactor");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);
	T iterator1 = vector.rbegin();
	T iterator2 = vector.rbegin();
	print_iterators_content<T>(iterator1, iterator2);
	compare_iterators<T>(&iterator1, &iterator2);
}

template<typename T>
static void	compare_reverse_iterators_of_different_vector(void)
{
	print_subheading("Iterators of differents vactors with the same value");
	print_instructions("vector1.push_back(number) x 8");
	print_instructions("vector2.push_back(number) x 8");
	ft::vector<int> vector1 = create_vector_of_random_integers(8, 200);
	ft::vector<int> vector2 = create_vector_of_random_integers(8, 200);
	displayVector(vector1);
	displayVector(vector2);
	T iterator1 = vector1.rbegin();
	T iterator2 = vector2.rbegin();
	print_iterators_content<T>(iterator1, iterator2);
	compare_iterators<T>(&iterator1, &iterator2);
}

template<typename T>
static void	compare_reverse_iterator_when_change_element_value(void)
{
	print_subheading("change value");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);

	T iterator = vector.rbegin();
	T* address1 = &iterator; 

	print_iterator("iterator", iterator);
	print_iterator("(iterator+2)", iterator + 2);
	
	print_instructions("vector[7] = vector[5];");
	vector[7] = vector[5];
	
	T* address2 = &iterator; 
	
	print_iterator("iterator", iterator);
	compare_iterators<T>(address1, address2);
}

#endif