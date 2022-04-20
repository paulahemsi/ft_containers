/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_of_bounds.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:04:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
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
		std::cout << "out of bounds - at(100): " << integers.at(100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "out of bounds - at(-1): " << integers.at(-1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "out of bounds [100]: " << integers[100] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "out of bounds [-1]: " << integers[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
