/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:28:38 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 21:28:51 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_get_allocator(void)
{
	print_title("GET_ALLOCATOR");

	ft::vector<int> myvector;
	int * pointer;

	// allocate an array with space for 5 elements using vector's allocator:
	pointer = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (size_t i = 0; i < 5; i++)
		myvector.get_allocator().construct(&pointer[i], i);

	std::cout << "The allocated array contains:";
	for (size_t i = 0; i < 5; i++)
		std::cout << ' ' << pointer[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (size_t i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&pointer[i]);
	myvector.get_allocator().deallocate(pointer,5);
}
