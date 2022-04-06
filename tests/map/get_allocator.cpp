/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:59:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/06 20:21:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests.hpp"

void test_get_allocator(void)
{
	print_title("GET ALLOCATOR");

	int pair_size;
	ft::map<char, int> my_map;
	ft::pair<const char, int>* my_pair;

	my_pair = my_map.get_allocator().allocate(5);

	pair_size = sizeof(ft::map<char,int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << pair_size << " bytes.\n";

	my_map.get_allocator().deallocate(my_pair, 5);


	return 0;
}
