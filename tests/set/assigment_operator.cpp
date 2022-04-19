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
	
	ft::set<char> first_set;
	ft::set<char> second_set;

	first_set.insert('x');
	first_set.insert('y'); 
	first_set.insert('z'); 

	print_instructions("print first_set");
	print_set(first_set);
	
	second_set = first_set;
	
	print_instructions("second_set = first_set");
	print_instructions("print second_set");
	print_set(second_set);

	print_instructions("first_set = ft::map<char,int>();");
	print_instructions("print first_set");
	first_set = ft::set<char>();

	std::cout << "Size of first: " << first_set.size() << std::endl;
	std::cout << "Size of second: " << second_set.size() << std::endl;
}
