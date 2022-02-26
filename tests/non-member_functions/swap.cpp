/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:01:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/26 12:17:35 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename Container, typename T>
static void swap_vectors(Container& vector_one_digit, Container& vector_three_digits)
{
	typename Container::iterator iter_pointing_to_3 = vector_one_digit.begin() + 3;
	typename Container::iterator iter_pointing_to_333 = vector_three_digits.end() - 3;

	print_instructions("std::cout << *iter_pointing_to_3 << std::endl;");
	std::cout << *iter_pointing_to_3 << std::endl;
	print_instructions("std::cout << *iter_pointing_to_333 << std::endl;");
	std::cout << *iter_pointing_to_333 << std::endl;

	print_instructions("swap(vector_one_digit, vector_three_digits);");
	swap(vector_one_digit, vector_three_digits);
	print_instructions("\ndisplayVector(vector_one_digit);");
	displayVector(vector_one_digit);
	print_instructions("displayVector(vector_three_digits);");
	displayVector(vector_three_digits);

	print_instructions("std::cout << *iter_pointing_to_3 << std::endl;");
	std::cout << *iter_pointing_to_3 << std::endl;
	print_instructions("std::cout << *iter_pointing_to_333 << std::endl;");
	std::cout << *iter_pointing_to_333 << std::endl;
}

static void swap_int(void)
{
	print_instructions("int");
	ft::vector<int> vector_one_digit;
	ft::vector<int> vector_three_digits;
	
	print_instructions("vector_one_digit.push_back(number) x 8");
	for(size_t i = 0; i < 8; i++)
		vector_one_digit.push_back(i);
	print_instructions("\ndisplayVector(vector_one_digit);");
	displayVector(vector_one_digit);

	print_instructions("vector_three_digits.push_back(number) x 9");
	for(size_t i = 9; i > 0; i--)
		vector_three_digits.push_back(i * 111);
	print_instructions("\ndisplayVector(vector_three_digits);");
	displayVector(vector_three_digits);

	ft::vector<int>::iterator iter_pointing_to_3 = vector_one_digit.begin() + 3;
	ft::vector<int>::iterator iter_pointing_to_333 = vector_three_digits.end() - 3;

	swap_vectors<ft::vector<int>, int>(vector_one_digit, vector_three_digits);
}

static void swap_string(void)
{
	print_instructions("string");
	ft::vector<std::string> vector_one_digit;
	ft::vector<std::string> vector_three_digits;
	
	print_instructions("vector_one_digit.push_back(number) x 8");
	for(size_t i = 0; i < 8; i++)
		vector_one_digit.push_back("a");
	print_instructions("\ndisplayVector(vector_one_digit);");
	displayVector(vector_one_digit);

	print_instructions("vector_three_digits.push_back(number) x 9");
	for(size_t i = 9; i > 0; i--)
		vector_three_digits.push_back("aaa");
	print_instructions("\ndisplayVector(vector_three_digits);");
	displayVector(vector_three_digits);

	swap_vectors<ft::vector<std::string>, std::string>(vector_one_digit, vector_three_digits);
}

void test_swap(void)
{
	print_title("SWAP");
	swap_int();
	swap_string();
}
