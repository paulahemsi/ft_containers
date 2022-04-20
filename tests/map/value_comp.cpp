/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_comp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:31:19 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_value_comp(void)
{
	print_title("VALUE COMPARE");

	ft::map<char, int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	std::cout << "mymap contains:\n";

	ft::pair<char, int> highest = *mymap.rbegin();          // last element

	ft::map<char, int>::iterator it = mymap.begin();

	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while ( mymap.value_comp()(*it++, highest) );
}
