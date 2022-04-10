/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:07:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/10 20:17:02 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_empty(void)
{
	print_title("EMPTY");

	ft::map<char, int>	mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	while (!mymap.empty())
	{
		ft::map<char, int>::iterator it = mymap.begin();
		std::cout << it->first << " => " << it->second << std::endl;
		mymap.erase(it);
	}
	std::cout << "map is empty" << std::endl;
}