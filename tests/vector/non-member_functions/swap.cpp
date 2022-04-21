/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:01:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 11:33:46 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "swap.tpp"

static void swap_int(void)
{
	print_subheading("int");
	ft::vector<int> vector1;
	ft::vector<int> vector2;
	
	fill_vectors<int>(1, 22, vector1, vector2);
	vector1.push_back(7777);
	vector2.push_back(3333);
	display_vectors(vector1, vector2);

	ft::vector<int>::reverse_iterator it1 = vector1.rbegin();
	ft::vector<int>::reverse_iterator it2 = vector2.rbegin();
	int ref1 = vector1[vector1.size() - 1];
	int ref2 = vector2[vector2.size() - 1];
	int *ptr1 = &ref1;
	int *ptr2 = &ref2;
	std::cout << "it1: " << *it1 << " ref1: " << ref1 << " *ptr1: " << *ptr1 << "\nit2: " << *it2 << " ref2: " << ref2 << " *ptr2: "<< *ptr2 << std::endl;
	swap_vectors(vector1, vector2);
	std::cout << "it1: " << *it1 << " ref1: " << ref1 << " *ptr1: " << *ptr1 << "\nit2: " << *it2 << " ref2: " << ref2 << " *ptr2: "<< *ptr2 << std::endl;
}

static void swap_string(void)
{
	print_subheading("string");
	ft::vector<std::string> vector1;
	ft::vector<std::string> vector2;

	fill_vectors<std::string>("one", "two", vector1, vector2);
	vector1.push_back("seven");
	vector2.push_back("nine");
	display_vectors(vector1, vector2);

	ft::vector<std::string>::reverse_iterator it1 = vector1.rbegin();
	ft::vector<std::string>::reverse_iterator it2 = vector2.rbegin();
	std::string ref1 = vector1[vector1.size() - 1];
	std::string ref2 = vector2[vector2.size() - 1];
	std::string *ptr1 = &ref1;
	std::string *ptr2 = &ref2;
	std::cout << "it1: " << *it1 << " ref1: " << ref1 << " *ptr1: " << *ptr1 << "\nit2: " << *it2 << " ref2: " << ref2 << " *ptr2: "<< *ptr2 << std::endl;
	swap_vectors(vector1, vector2);
	std::cout << "it1: " << *it1 << " ref1: " << ref1 << " *ptr1: " << *ptr1 << "\nit2: " << *it2 << " ref2: " << ref2 << " *ptr2: "<< *ptr2 << std::endl;
}

void test_swap(void)
{
	print_title("SWAP");
	swap_int();
	swap_string();
}
