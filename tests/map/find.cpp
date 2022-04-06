/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:09:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/06 20:23:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void print_found(ft::map<float, float>::const_iterator it, ft::map<float, float>::const_iterator end)
{
	if (it != end)
		std::cout << CYAN << "Found: key " << it->first << " value " << it->second << RESET << std::endl;
	else 
		std::cout << ORANGE << "not found" << RESET << std::endl;
}

void test_find(void)
{
	print_title("FIND");

	ft::map<float, float> map_to_test = create_map_of_floats(7);

	std::cout << std::endl;
	ft::map<float, float>::iterator end = map_to_test.end();
	for (float i = 4; i < 9; i++)
	{
		float number_to_find = i / 10 * i;
		std::cout << "number to find: " << number_to_find << std::endl;
		ft::map<float, float>::iterator found = map_to_test.find((number_to_find));
		print_found(found, end);
	}

	print_title("CONST FIND");

	for (float i = 0; i < 4; i++)
	{
		float number_to_find = i / 10 * i;
		std::cout << "number to find: " << number_to_find << std::endl;
		ft::map<float, float>::const_iterator found = map_to_test.find((number_to_find));
		print_found(found, end);
	}
}
