/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/28 21:12:58 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TPP
# define ITERATORS_TPP

#include "tests.hpp"

template<typename T>
static void print_iterator(std::string name, T iterator)
{
	std::cout << L_GRAY << "*" << name << ": " << RESET << *iterator << "\t"
				<< L_GRAY << name << ": " << RESET << &iterator << std::endl;
}
template<typename T>
static void print_iterators(T iterator1, T iterator2)
{
	print_iterator<T>("iterator1", iterator1);
	print_iterator<T>("iterator2", iterator2);
}

template<typename T>
static void compare_iterators(T iterator1, T iterator2)
{
	std::cout << L_GRAY << "(iterator1 == iterator2): " << RESET << (iterator1 == iterator2) << std::endl;
	std::cout << L_GRAY << "(iterator1 < iterator2): " << RESET << (iterator1 < iterator2) << std::endl;
}

template<typename T>
static void	iterators_of_same_vector(void)
{
	print_subheading("Iterators of the same vactor");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);
	print_iterators<T>(vector.begin(), vector.begin());
	compare_iterators<T>(vector.begin(), vector.begin());
}

template<typename T>
static void	iterators_of_differents_vector(void)
{
	print_subheading("Iterators of differents vactors with the same value");
	print_instructions("vector1.push_back(number) x 8");
	print_instructions("vector2.push_back(number) x 8");
	ft::vector<int> vector1 = create_vector_of_random_integers(8, 200);
	ft::vector<int> vector2 = create_vector_of_random_integers(8, 200);
	displayVector(vector1);
	displayVector(vector2);
	print_iterators<T>(vector1.begin(), vector2.begin());
	compare_iterators<T>(vector1.begin(), vector2.begin());
}

template<typename T>
static void	iterator_when_change_value(void)
{
	print_subheading("change value");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);

	T iterator = vector.begin();

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