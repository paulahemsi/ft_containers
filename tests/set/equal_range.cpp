/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:34:45 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_equal_range(void)
{
	print_title("EQUAL RANGE");
	print_title("char - int");

	ft::set<char> myset;

	print_instructions("myset['a'] = 10;\nmyset['b'] = 20;\nmyset['c'] = 30;\n");

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');

	ft::pair<ft::set<char>::iterator,ft::set<char>::iterator> ret;
	ret = myset.equal_range('b');

	print_subheading("lower bound points to: ");
	std::cout << *(ret.first) << std::endl;

	print_subheading("upper bound points to: ");
	std::cout << *(ret.second) << std::endl;

	print_title("int - int");

	ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret_int;
	ft::set<int> set = create_set_of_random_integers(40000, 1);
	ret_int = set.equal_range(977);

	print_subheading("lower bound points to: ");
	std::cout << *(ret_int.first) << std::endl;

	print_subheading("upper bound points to: ");
	std::cout << *(ret_int.second) << std::endl;

	ret_int = set.equal_range(500);

	print_subheading("lower bound points to: ");
	std::cout << *(ret_int.first) << std::endl;

	print_subheading("upper bound points to: ");
	std::cout << *(ret_int.second) << std::endl;

}
