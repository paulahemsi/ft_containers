/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:16:02 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 17:17:31 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <time.h>

int main(void)
{
	clock_t start;
	clock_t end;
	clock_t elapsed_time;

	start = clock();

	std::cout.setf(std::ios::boolalpha);
	test_constructors();
	test_iterators();
	test_find();
	test_get_allocator();
	test_insert();
	test_erase();
	test_size();
	test_count();
	test_lower_bound();
	test_upper_bound();
	test_equal_range();
	test_assigment_operator();
	test_empty();
	test_value_comp();
	max_size();
	test_swap();
	test_equality_operator();
	less_than_comparison();

	end = clock();
	elapsed_time = end - start;
	print_title(VERSION);
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;

	return (0);
}
