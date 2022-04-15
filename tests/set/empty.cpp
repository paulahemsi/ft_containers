/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:07:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 16:40:26 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_empty(void)
{
	print_title("EMPTY");

	ft::set<char>	myset;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');

	while (!myset.empty())
	{
		ft::set<char>::iterator it = myset.begin();
		std::cout << *it << std::endl;
		myset.erase(it);
	}
	std::cout << "set is empty" << std::endl;
}
