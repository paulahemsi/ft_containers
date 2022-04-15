/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:09:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 16:50:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void print_found(ft::set<float>::const_iterator it, ft::set<float>::const_iterator end)
{
	if (it != end)
		std::cout << CYAN << "Found: " << *it << RESET << std::endl;
	else 
		std::cout << ORANGE << "not found" << RESET << std::endl;
}

void test_find(void)
{
	print_title("FIND");

	ft::set<float> set_to_test = create_set_of_floats(7);

	std::cout << std::endl;
	ft::set<float>::iterator end = set_to_test.end();
	for (float i = 4; i < 9; i++)
	{
		float number_to_find = i / 10 * i;
		std::cout << "number to find: " << number_to_find << std::endl;
		ft::set<float>::iterator found = set_to_test.find((number_to_find));
		print_found(found, end);
	}

	print_title("CONST FIND");

	for (float i = 0; i < 4; i++)
	{
		float number_to_find = i / 10 * i;
		std::cout << "number to find: " << number_to_find << std::endl;
		ft::set<float>::const_iterator found = set_to_test.find((number_to_find));
		print_found(found, end);
	}
}
