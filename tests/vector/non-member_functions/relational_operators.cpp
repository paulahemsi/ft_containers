/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:10:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/26 10:46:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "comparison.hpp"

static void test_string_vector(void)
{
	print_subheading("string");
	ft::vector<std::string> one_vector(8, "one");
	ft::vector<std::string> another_vector(8, "another");
	ft::vector<std::string> and_other_vector(5, "and_other");

	print_vectors<ft::vector<std::string> >(one_vector, another_vector, and_other_vector);
	call_comparsions<ft::vector<std::string> >(one_vector, another_vector, and_other_vector);
}

static void test_int_vector(void)
{
	print_subheading("int");
	ft::vector<int> one_vector(8, 1);
	ft::vector<int> another_vector(8, 2);
	ft::vector<int> and_other_vector(5, 1);

	print_vectors<ft::vector<int> >(one_vector, another_vector, and_other_vector);
	call_comparsions<ft::vector<int> >(one_vector, another_vector, and_other_vector);
}

void test_relational_operators(void)
{
	print_title("RELATIONAL OPERATORS");

	test_string_vector();
	test_int_vector();
}
