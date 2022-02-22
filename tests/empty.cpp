/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:18:56 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/22 20:19:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_empty(void)
{
	print_title(".EMPTY");

	print_instructions("ft::vector<int> my_vector;");
	ft::vector<int> my_vector;
	displayVector(my_vector);

	print_instructions("my_vector.empty(): ");
	std::cout << my_vector.empty() << std::endl;
	print_instructions("my_vector.push_back(137);");
	my_vector.push_back(137);
	displayVector(my_vector);
	print_instructions("my_vector.empty(): ");
	std::cout << my_vector.empty() << std::endl;
	print_instructions("my_vector.pop_back();");
	my_vector.pop_back();
	print_instructions("my_vector.empty(): ");
	std::cout << my_vector.empty() << std::endl;

	print_instructions("ft::vector<int> four_elements(4);");
	ft::vector<int> four_elements(4);
	displayVector(four_elements);
	print_instructions("four_elements.empty(): ");
	std::cout << four_elements.empty() << std::endl;
}
