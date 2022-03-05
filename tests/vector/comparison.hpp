/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:12:03 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/24 22:28:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARISON_HPP
#define COMPARISON_HPP

#include "tests.hpp"

template <class Container>
void is_equal_to(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("(one_vector == one_vector)");
	std::cout << (one_vector == one_vector) << std::endl;
	print_instructions("(one_vector == another_vector)");
	std::cout << (one_vector == another_vector) << std::endl;
	print_instructions("(one_vector == and_other_vector)");
	std::cout << (one_vector == and_other_vector) << std::endl;
}

template <class Container>
void is_not_equal_to(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("(one_vector != one_vector)");
	std::cout << (one_vector != one_vector) << std::endl;
	print_instructions("(one_vector != another_vector)");
	std::cout << (one_vector != another_vector) << std::endl;
	print_instructions("(one_vector != and_other_vector)");
	std::cout << (one_vector != and_other_vector) << std::endl;
}

template <class Container>
void is_greater_than(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("(one_vector > one_vector)");
	std::cout << (one_vector > one_vector) << std::endl;
	print_instructions("(one_vector > another_vector)");
	std::cout << (one_vector > another_vector) << std::endl;
	print_instructions("(one_vector > and_other_vector)");
	std::cout << (one_vector > and_other_vector) << std::endl;
}

template <class Container>
void is_greater_than_or_equal_to(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("(one_vector >= one_vector)");
	std::cout << (one_vector >= one_vector) << std::endl;
	print_instructions("(one_vector >= another_vector)");
	std::cout << (one_vector >= another_vector) << std::endl;
	print_instructions("(one_vector >= and_other_vector)");
	std::cout << (one_vector >= and_other_vector) << std::endl;
}

template <class Container>
void is_less_than(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("(one_vector > one_vector)");
	std::cout << (one_vector > one_vector) << std::endl;
	print_instructions("(one_vector > another_vector)");
	std::cout << (one_vector > another_vector) << std::endl;
	print_instructions("(one_vector > and_other_vector)");
	std::cout << (one_vector > and_other_vector) << std::endl;
}

template <class Container>
void is_less_than_or_equal_to(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("(one_vector <= one_vector)");
	std::cout << (one_vector <= one_vector) << std::endl;
	print_instructions("(one_vector <= another_vector)");
	std::cout << (one_vector <= another_vector) << std::endl;
	print_instructions("(one_vector <= and_other_vector)");
	std::cout << (one_vector <= and_other_vector) << std::endl;
}

template <class Container>
void print_vectors(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	print_instructions("one_vector:");
	displayVector(one_vector);
	print_instructions("another_vector:");
	displayVector(another_vector);
	print_instructions("and_other_vector:");
	displayVector(and_other_vector);
}

template <class Container>
void call_comparsions(
	Container & one_vector,
	Container & another_vector,
	Container & and_other_vector
)
{
	is_equal_to<Container>(one_vector, another_vector, and_other_vector);
	is_not_equal_to<Container>(one_vector, another_vector, and_other_vector);
	is_greater_than<Container>(one_vector, another_vector, and_other_vector);
	is_greater_than_or_equal_to<Container>(one_vector, another_vector, and_other_vector);
	is_less_than<Container>(one_vector, another_vector, and_other_vector);
	is_less_than_or_equal_to<Container>(one_vector, another_vector, and_other_vector);
}

#endif
