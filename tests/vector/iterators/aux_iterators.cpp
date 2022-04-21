/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_iterators.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:28:44 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/03 16:48:01 by lfrasson         ###   ########.fr       */
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

void getEnd(ft::vector<int>& vector, ft::vector<int>::iterator& iterator)
{
	iterator = vector.end();
}

void getEnd(ft::vector<int>& vector, ft::vector<int>::const_iterator& iterator)
{
	iterator = vector.end();
}

void getEnd(ft::vector<int>& vector, ft::vector<int>::reverse_iterator& iterator)
{
	iterator = vector.rend();
}

// void getEnd(ft::vector<int>& vector, ft::vector<int>::const_reverse_iterator& iterator)
// {
// 	iterator = vector.rend();
// }

static std::string *to_string (int number)
{
	std::string *string = new std::string();
	while (number / 10)
	{
		string->insert(0, 1, number % 10 + '0');
		number /= 10;
	}
	string->insert(0, 1, number % 10 + '0');
	return string;

}

void	change_value(ft::vector<int>& vector, int index1, int index2)
{
	std::string *index;
	std::string instruction("");

	instruction.append("vector[");
	index = to_string(index1);
	instruction.append(*index);
	delete index;
	instruction.append("] = vector[");
	index = to_string(index2);
	instruction.append(*index);
	delete index;
	instruction.append("];");
	print_instructions(instruction);
	vector[index1] = vector[index2];
}

ft::vector<int>	create_and_display_vector(void)
{
	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector = create_vector_of_random_integers(8, 200);
	displayVector(vector);
	return vector;
}