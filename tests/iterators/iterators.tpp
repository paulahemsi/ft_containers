/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/03 16:57:47 by lfrasson         ###   ########.fr       */
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
	T iterator1;
	T iterator2;
	
	print_subheading("Compare iterators of the same vactor");
	ft::vector<int> vector = create_and_display_vector(); 
	getBegin(vector, iterator1);
	getBegin(vector, iterator2);
	print_iterators_content<T>(iterator1, iterator2);
	compare_iterators<T>(&iterator1, &iterator2);
}

template<typename T>
static void	compare_iterators_of_different_vector(void)
{
	T iterator1;
	T iterator2;
	
	print_subheading("Iterators of different vactors with the same value");
	ft::vector<int> vector1 = create_and_display_vector(); 
	ft::vector<int> vector2 = create_and_display_vector(); 
	getBegin(vector1, iterator1);
	getBegin(vector2, iterator2);
	print_iterators_content<T>(iterator1, iterator2);
	compare_iterators<T>(&iterator1, &iterator2);
}

template<typename T>
static void	compare_iterator_when_change_element_value(int index1, int index2)
{
	T iterator;
	
	print_subheading("Iterators when change element value");
	ft::vector<int> vector = create_and_display_vector(); 
	getBegin(vector, iterator);
	T* address1 = &iterator; 
	print_iterator("iterator", iterator);
	print_iterator("(iterator+2)", iterator + 2);
	change_value(vector, index1, index2);
	T* address2 = &iterator; 
	print_iterator("iterator", iterator);
	compare_iterators<T>(address1, address2);
}

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