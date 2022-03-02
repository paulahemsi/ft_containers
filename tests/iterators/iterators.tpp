/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 16:46:57 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TPP
# define ITERATORS_TPP

#include "iterators.hpp"

template<typename T>
static void print_iterator(std::string name, T iterator)
{
	std::cout << L_GRAY << "*" << name << ": " << RESET << *iterator << std::endl;
}

template<typename T>
static void print_iterators_content(T iterator1, T iterator2)
{
	print_iterator<T>("iterator1", iterator1);
	print_iterator<T>("iterator2", iterator2);
}

template<typename T>
static void compare_iterators(T* iterator1, T* iterator2)
{
	std::cout << L_GRAY << "(*iterator1 == *iterator2): " << RESET << (*(*iterator1) == *(*iterator2)) << std::endl;
	std::cout << L_GRAY << "(&iterator1 == &iterator2): " << RESET << (*(&iterator1) == *(&iterator2)) << std::endl;
	std::cout << L_GRAY << "(iterator1 == iterator2): " << RESET << (*iterator1 == *iterator2) << std::endl;
	std::cout << L_GRAY << "(iterator1 < iterator2): " << RESET << (*iterator1 < *iterator2) << std::endl;
}

template<typename T>
static void	compare_iterators_of_same_vector(void)
{
	print_subheading("Compare iterators of the same vactor");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);

	T iterator1 = vector.begin();
	T iterator2 = vector.begin();
	print_iterators_content<T>(iterator1, iterator2);
	compare_iterators<T>(&iterator1, &iterator2);
}

template<typename T>
static void	compare_iterators_of_different_vector(void)
{
	print_subheading("Iterators of different vactors with the same value");
	print_instructions("vector1.push_back(number) x 8");
	print_instructions("vector2.push_back(number) x 8");
	ft::vector<int> vector1 = create_vector_of_random_integers(8, 200);
	ft::vector<int> vector2 = create_vector_of_random_integers(8, 200);
	displayVector(vector1);
	displayVector(vector2);
	T iterator1 = vector1.begin();
	T iterator2 = vector2.begin();
	print_iterators_content<T>(iterator1, iterator2);
	compare_iterators<T>(&iterator1, &iterator2);
}

template<typename T>
static void	compare_iterator_when_change_element_value(void)
{
	print_subheading("Iterators when change element value");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);

	T iterator = vector.begin();
	T* address1 = &iterator; 

	print_iterator("iterator", iterator);
	print_iterator("(iterator+2)", iterator + 2);
	
	print_instructions("vector[0] = vector[2];");
	vector[0] = vector[2];
	
	T* address2 = &iterator; 
	
	print_iterator("iterator", iterator);
	compare_iterators<T>(address1, address2);
}

#endif