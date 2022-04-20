/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigment_operator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:02:50 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_assigment_operator(void)
{
	print_title("ASSIGMENT OPERATOR");
	
	ft::map<char,int> first_map;
	ft::map<char,int> second_map;

	first_map['x']=8;
	first_map['y']=16;
	first_map['z']=32;

	print_instructions("print first_map");
	print_map(first_map);
	
	second_map = first_map;                // second now contains 3 ints
	
	print_instructions("second_map = first_map");
	print_instructions("print second_map");
	print_map(second_map);

	print_instructions("first_map = ft::map<char,int>();");
	print_instructions("print first_map");
	first_map = ft::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first_map.size() << std::endl;
	std::cout << "Size of second: " << second_map.size() << std::endl;
}
