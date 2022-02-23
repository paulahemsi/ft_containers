/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:04:38 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 21:04:45 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_data(void)
{
	print_title("DATA");

	ft::vector<std::string> string_vector;
	print_instructions("string_vector.push_back(name) x 5");
	string_vector.push_back("Ada");
	string_vector.push_back("Bell");
	string_vector.push_back("Djamila");
	string_vector.push_back("Chimamanda");
	string_vector.push_back("Elza");
	displayVector(string_vector);

	for(size_t i = 0; i < string_vector.size(); i++)
	{
		print_instructions("std::cout << *(string_vector.data() + i) << std::endl;");
		std::cout << *(string_vector.data() + i) << std::endl;
	}
}
