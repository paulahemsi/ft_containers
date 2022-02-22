/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_operator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:34:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 20:35:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_equal_operator(void)
{
	print_title("  =  ");
	print_instructions("ft::vector<std::string> string_vector2(2, nothing);");
	ft::vector<std::string> string_vector2(2, "nothing");
	displayVector(string_vector2);
	ft::vector<std::string> string_vector;
	print_instructions("string_vector.push_back(name) x 5");
	string_vector.push_back("Ada");
	string_vector.push_back("Bell");
	string_vector.push_back("Djamila");
	string_vector.push_back("Chimamanda");
	string_vector.push_back("Elza");
	displayVector(string_vector);
	std::cout << L_GRAY << "string_vector2 = string_vector;" << RESET << std::endl;
	string_vector2 = string_vector;
	std::cout << "string_vector2: " << std::endl;
	displayVector(string_vector2);

	print_instructions("ft::vector<int> int_vector2(2, 2);");
	ft::vector<int> int_vector2(2, 2);
	displayVector(int_vector2);
	ft::vector<int> int_vector;
	print_instructions("int_vector.push_back(name) x 5");
	int_vector.push_back(1);
	int_vector.push_back(2);
	int_vector.push_back(3);
	int_vector.push_back(4);
	int_vector.push_back(5);
	displayVector(int_vector);
	std::cout << L_GRAY << "int_vector2 = int_vector;" << RESET << std::endl;
	int_vector2 = int_vector;
	std::cout << "int_vector2: " << std::endl;
	displayVector(int_vector2);
}