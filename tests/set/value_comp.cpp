/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_comp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:31:19 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 17:16:19 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_value_comp(void)
{
	print_title("VALUE COMPARE");
	
	ft::set<int> myset;

	ft::set<int>::value_compare mycomp = myset.value_comp();

	for (int i = 0; i <= 5; i++) myset.insert(i);

	std::cout << "myset contains:";

	int highest = *myset.rbegin();
	ft::set<int>::iterator it = myset.begin();
	
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
}
