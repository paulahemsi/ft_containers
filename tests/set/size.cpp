/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:36:23 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 17:09:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_size(void)
{
	print_title("SIZE");
	
	ft::set<char> myset;
	
	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	std::cout << "myset.size() is " << myset.size() << '\n';

	myset.erase('x');
	std::cout << "myset.size() is " << myset.size() << '\n';

	myset.erase('b');
	std::cout << "myset.size() is " << myset.size() << '\n';
}
