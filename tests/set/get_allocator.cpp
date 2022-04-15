/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:59:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 16:54:47 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests.hpp"

void test_get_allocator(void)
{
	print_title("GET ALLOCATOR");

	int char_size;
	ft::set<char> my_set;
	char* my_char;

	my_char = my_set.get_allocator().allocate(5);

	char_size = sizeof(ft::set<char>::value_type) * 5;

	std::cout << "The allocated array has a size of " << char_size << " bytes.\n";

	my_set.get_allocator().deallocate(my_char, 5);

	return ;
}
