/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:02:19 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 21:02:30 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_insert(void)
{
	print_title(".INSERT");

	print_instructions("std::vector<int> integers;");
	ft::vector<int> integers;
	displayVector(integers);
	print_instructions("integers.insert(integers.begin(), 7);");
	std::cout << "first element inserted: " << *(integers.insert(integers.begin(), 7)) << std::endl;
	displayVector(integers);

	print_instructions("integers.insert(integers.begin() + 1, 77);");
	std::cout << "first element inserted: " << *(integers.insert(integers.begin() + 1, 77)) << std::endl;
	displayVector(integers);
	print_instructions("integers.push_back(number) x 8");
	integers.push_back(50);
	integers.push_back(1);
	integers.push_back(987);
	integers.push_back(1001);
	integers.push_back(50);
	integers.push_back(1);
	integers.push_back(987);
	integers.push_back(1001);
	displayVector(integers);
	print_instructions("integers.insert(integers.end() - 3, 777);");
	std::cout << "first element inserted: " << *(integers.insert(integers.end() - 3, 777)) << std::endl;
	displayVector(integers);
	print_instructions("integers.insert(integers.begin() + 1, 3, 777);");
	integers.insert(integers.begin() + 1, 3, 777);
	displayVector(integers);
	print_instructions("integers.insert(integers.begin() + 3, 10, 1111);");
	integers.insert(integers.begin() + 3, 10, 1111);
	displayVector(integers);

	std::vector<int> vector_to_insert;
	vector_to_insert.push_back(1);
	vector_to_insert.push_back(2);
	vector_to_insert.push_back(3);
	vector_to_insert.push_back(4);
	vector_to_insert.push_back(5);
	vector_to_insert.push_back(6);
	vector_to_insert.push_back(7);
	vector_to_insert.push_back(8);
	print_instructions("integers.insert(integers.begin() + 2, vector_to_insert.begin(), 1111);");
	integers.insert(integers.begin() + 2, vector_to_insert.begin(), vector_to_insert.begin() + 4);
	displayVector(integers);
}