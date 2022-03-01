/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:59:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/01 10:11:40 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATORS_TPP
# define REVERSE_ITERATORS_TPP

#include "iterators.hpp"

template<typename T>
static void	reverse_iterators_of_same_vector(void)
{
	print_subheading("Iterators of the same vactor");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);
	print_iterators<T>(vector.rbegin(), vector.rbegin());
	compare_iterators<T>(vector.rbegin(), vector.rbegin());
}

template<typename T>
static void	reverse_iterators_of_differents_vector(void)
{
	print_subheading("Iterators of differents vactors with the same value");
	print_instructions("vector1.push_back(number) x 8");
	print_instructions("vector2.push_back(number) x 8");
	ft::vector<int> vector1 = create_vector_of_random_integers(8, 200);
	ft::vector<int> vector2 = create_vector_of_random_integers(8, 200);
	displayVector(vector1);
	displayVector(vector2);
	print_iterators<T>(vector1.rbegin(), vector2.rbegin());
	compare_iterators<T>(vector1.rbegin(), vector2.rbegin());
}

template<typename T>
static void	reverse_iterator_when_change_value(void)
{
	print_subheading("change value");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);

	T iterator = vector.rbegin();

	std::cout << L_GRAY << "*iterator: " << RESET << *iterator << "\t"
				<< L_GRAY << "iterator: " << RESET << &iterator << std::endl;
	std::cout << L_GRAY << "*(iterator+2): " << RESET << *(iterator + 2) << "\t"
				<< L_GRAY << "(iterator+2): " << RESET << &iterator + 2 << std::endl;
	
	print_instructions("vector2[0] = vector1[0];");
	vector[0] = vector[2];
	std::cout << L_GRAY << "*iterator: " << RESET << *iterator << "\t"
				<< L_GRAY << "iterator: " << RESET << &iterator << std::endl;
}

#endif