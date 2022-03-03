/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_iterators.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:28:44 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 21:41:13 by lfrasson         ###   ########.fr       */
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