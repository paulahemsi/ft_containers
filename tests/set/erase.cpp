/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:28:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 16:49:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_erase(void)
{
	print_title("ERASE");

	ft::set<float> set = create_set_of_floats(9);

	print_subheading("erase with iterator");
	print_instructions("find 0.1?");
	print_found(set.find(0.1), set.end());
	print_instructions("0.1 erased");
	set.erase(set.find(0.1));
	print_instructions("find 0.1?");
	print_found(set.find(0.1), set.end());

	print_subheading("erase with key");
	print_instructions("find 0.4?");
	print_found(set.find(0.4), set.end());
	print_instructions("0.4 erased");
	std::cout << set.erase(0.4) << " element was erased" << std::endl;
	print_instructions("find 0.4?");
	print_found(set.find(0.4), set.end());
	print_instructions("try to erase 0.4 again");
	std::cout << set.erase(0.4) << " element was erased" << std::endl;

	print_subheading("erase iterators range");
	print_instructions("erase from 2.5 to 6.4 -not included");
	set.erase(set.begin(), set.find(6.4));
	print_instructions("find 0.9?");
	print_found(set.find(0.9), set.end());
	print_instructions("find 1.6?");
	print_found(set.find(1.6), set.end());
	print_instructions("find 2.5?");
	print_found(set.find(2.5), set.end());
	print_instructions("find 3.6?");
	print_found(set.find(3.6), set.end());
	print_instructions("find 4.9?");
	print_found(set.find(4.9), set.end());
	print_instructions("find 6.4?");
	print_found(set.find(6.4), set.end());
	//*float imprecision as key (same as original version):
	print_instructions("find 8.1?");
	print_found(set.find(8.1), set.end());
}
