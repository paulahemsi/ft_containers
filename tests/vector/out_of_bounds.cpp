/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_of_bounds.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:04:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/21 13:32:10 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_out_of_bounds(void)
{
	print_title("OUT_OF_BOUNDS");

	print_instructions("ft::vector<int> integers(10);");
	ft::vector<int> integers(10);
	try
	{
		std::cout << "out of bounds - at(100): " << std::endl;
		integers.at(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "out of bounds - at(-1): " << std::endl;
		integers.at(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
