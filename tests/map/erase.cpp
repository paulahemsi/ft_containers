/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:28:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/06 23:42:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_erase(void)
{
	print_title("ERASE");

	ft::map<float, float> map = create_map_of_floats(9);

	print_subheading("erase with iterator");
	print_instructions("find 0.1?");
	print_found(map.find(0.1), map.end());
	print_instructions("0.1 erased");
	map.erase(map.find(0.1));
	print_instructions("find 0.1?");
	print_found(map.find(0.1), map.end());

	print_subheading("erase with key");
	print_instructions("find 0.4?");
	print_found(map.find(0.4), map.end());
	print_instructions("0.4 erased");
	std::cout << map.erase(0.4) << " element was erased" << std::endl;
	print_instructions("find 0.4?");
	print_found(map.find(0.4), map.end());
	print_instructions("try to erase 0.4 again");
	std::cout << map.erase(0.4) << " element was erased" << std::endl;

	print_subheading("erase iterators range");
	print_instructions("erase from 2.5 to 6.4 -not included");
	map.erase(map.find(2.5), map.find(6.4));
	print_instructions("find 2.5?");
	print_found(map.find(2.5), map.end());
	print_instructions("find 3.6?");
	print_found(map.find(3.6), map.end());
	print_instructions("find 4.9?");
	print_found(map.find(4.9), map.end());
	print_instructions("find 6.4?");
	print_found(map.find(6.4), map.end());
}
