/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_iterators.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:28:44 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 20:57:23 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

void getBegin(ft::vector<int>& vector, ft::vector<int>::iterator& iterator)
{
	iterator = vector.begin();
}

void getBegin(ft::vector<int>& vector, ft::vector<int>::const_iterator& iterator)
{
	iterator = vector.begin();
}

void getBegin(ft::vector<int>& vector, ft::vector<int>::reverse_iterator& iterator)
{
	iterator = vector.rbegin();
}

// void getBegin(ft::vector<int>& vector, ft::vector<int>::const_reverse_iterator& iterator)
// {
// 	iterator = vector.rbegin();
// }

void	change_value(ft::vector<int>& vector, int index1, int index2)
{
	std::string instruction("");

	instruction.append("vector[");
	instruction.append(std::to_string(index1));
	instruction.append("] = vector[");
	instruction.append(std::to_string(index2));
	instruction.append("];");
	print_instructions(instruction);
	vector[index1] = vector[index2];
}

static void	iterate_vector_changing_value(ft::vector<int>& vector)
{
	for (ft::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it)
		*it *= 2;
}

static void	iterate_vector_printing(ft::vector<int>& vector)
{
	for (ft::vector<int>::const_iterator it = vector.begin() ; it != vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void iterate_through_vector_changing_values(void)
{
	print_subheading("Iterate through vector changing values");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	iterate_vector_changing_value(vector);
	iterate_vector_printing(vector);
}

void iterate_through_vector(void)
{
	print_subheading("Iterate through vector");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	iterate_vector_printing(vector);
}