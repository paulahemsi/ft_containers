/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:10:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/22 20:10:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_relational_operators(void)
{
	print_title("RELATIONAL OPERATORS");

	ft::vector<std::string> one_vector(8, "one");
	ft::vector<std::string> another_vector(8, "another");
	ft::vector<std::string> and_other_vector(5, "and_other");

	print_instructions("(one_vector == one_vector)");
	std::cout << (one_vector == one_vector) << std::endl;
	print_instructions("(one_vector == another_vector)");
	std::cout << (one_vector == another_vector) << std::endl;
	print_instructions("(one_vector == and_other_vector)");
	std::cout << (one_vector == and_other_vector) << std::endl;

	print_instructions("(one_vector != one_vector)");
	std::cout << (one_vector != one_vector) << std::endl;
	print_instructions("(one_vector != another_vector)");
	std::cout << (one_vector != another_vector) << std::endl;
	print_instructions("(one_vector != and_other_vector)");
	std::cout << (one_vector != and_other_vector) << std::endl;

	print_instructions("(one_vector > one_vector)");
	std::cout << (one_vector > one_vector) << std::endl;
	print_instructions("(one_vector > another_vector)");
	std::cout << (one_vector > another_vector) << std::endl;
	print_instructions("(one_vector > and_other_vector)");
	std::cout << (one_vector > and_other_vector) << std::endl;

	print_instructions("(one_vector >= one_vector)");
	std::cout << (one_vector >= one_vector) << std::endl;
	print_instructions("(one_vector >= another_vector)");
	std::cout << (one_vector >= another_vector) << std::endl;
	print_instructions("(one_vector >= and_other_vector)");
	std::cout << (one_vector >= and_other_vector) << std::endl;

	print_instructions("(one_vector < one_vector)");
	std::cout << (one_vector < one_vector) << std::endl;
	print_instructions("(one_vector < another_vector)");
	std::cout << (one_vector < another_vector) << std::endl;
	print_instructions("(one_vector < and_other_vector)");
	std::cout << (one_vector < and_other_vector) << std::endl;

	print_instructions("(one_vector <= one_vector)");
	std::cout << (one_vector <= one_vector) << std::endl;
	print_instructions("(one_vector <= another_vector)");
	std::cout << (one_vector <= another_vector) << std::endl;
	print_instructions("(one_vector <= and_other_vector)");
	std::cout << (one_vector <= and_other_vector) << std::endl;
}
