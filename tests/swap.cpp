/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:01:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 21:02:02 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_swap(void)
{
	print_title("SWAP");

	ft::vector<int> vector1;
	print_instructions("vector1.push_back(number) x 8");
	vector1.push_back(0);
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector1.push_back(4);
	vector1.push_back(5);
	vector1.push_back(6);
	vector1.push_back(7);
	displayVector(vector1);

	ft::vector<int> vector2;
	print_instructions("vector2.push_back(number) x 9");
	vector2.push_back(999999999);
	vector2.push_back(88888888);
	vector2.push_back(7777777);
	vector2.push_back(666666);
	vector2.push_back(55555);
	vector2.push_back(4444);
	vector2.push_back(333);
	vector2.push_back(22);
	vector2.push_back(1);
	displayVector(vector2);

	ft::vector<int>::iterator iter_3 = vector1.begin() + 3;
	ft::vector<int>::iterator iter_333 = vector2.end() - 3;

	print_instructions("std::cout << *iter_3 << std::endl;");
	std::cout << *iter_3 << std::endl;
	print_instructions("std::cout << *iter_333 << std::endl;");
	std::cout << *iter_333 << std::endl;

	print_instructions("swap(vector1, vector2);");
	swap(vector1, vector2);
	print_instructions("\ndisplayVector(vector1);");
	displayVector(vector1);
	print_instructions("displayVector(vector2);");
	displayVector(vector2);

	print_instructions("std::cout << *iter_3 << std::endl;");
	std::cout << *iter_3 << std::endl;
	print_instructions("std::cout << *iter_333 << std::endl;");
	std::cout << *iter_333 << std::endl;
}