/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:44:11 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/25 10:56:25 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

static void	reverse_iterators_of_same_vector(void)
{
	print_subheading("Iterators of the same vactor");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);
	print_iterators<ft::vector<int>::reverse_iterator>(vector.rbegin(), vector.rbegin());
	compare_iterators<ft::vector<int>::reverse_iterator>(vector.rbegin(), vector.rbegin());
}

static void	reverse_iterators_of_differents_vector(void)
{
	print_subheading("Iterators of differents vactors with the same value");
	print_instructions("vector1.push_back(number) x 8");
	print_instructions("vector2.push_back(number) x 8");
	ft::vector<int> vector1 = create_vector_of_random_integers(8, 200);
	ft::vector<int> vector2 = create_vector_of_random_integers(8, 200);
	displayVector(vector1);
	displayVector(vector2);
	print_iterators<ft::vector<int>::reverse_iterator>(vector1.rbegin(), vector2.rbegin());
	compare_iterators<ft::vector<int>::reverse_iterator>(vector1.rbegin(), vector2.rbegin());
}

static void	reverse_iterator_when_change_value(void)
{
	print_subheading("change value");
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);

	ft::vector<int>::reverse_iterator iterator = vector.rbegin();

	std::cout << L_GRAY << "*iterator: " << RESET << *iterator << "\t"
				<< L_GRAY << "iterator: " << RESET << &iterator << std::endl;
	std::cout << L_GRAY << "*(iterator+2): " << RESET << *(iterator + 2) << "\t"
				<< L_GRAY << "(iterator+2): " << RESET << &iterator + 2 << std::endl;
	
	print_instructions("vector2[0] = vector1[0];");
	vector[0] = vector[2];
	std::cout << L_GRAY << "*iterator: " << RESET << *iterator << "\t"
				<< L_GRAY << "iterator: " << RESET << &iterator << std::endl;
}

void test_reverse_iterators(void)
{
	print_title("REVERSE ITERATORS");
	reverse_iterators_of_same_vector();
	reverse_iterators_of_differents_vector();
	reverse_iterator_when_change_value();
	
	// ft::vector<int>::reverse_iterator rend = integers.rend();
	// while (reverse_iteratorIntegers1 <= rend)
	// {
	// 	std::cout << *reverse_iteratorIntegers1 << std::endl;
	// 	reverse_iteratorIntegers1++;
	// }
}