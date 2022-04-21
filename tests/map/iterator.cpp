/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:01:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 19:34:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_iterators(void)
{
	print_title("ITERATORS");
	
	ft::map<int, int> map = create_map_of_random_integers(8, 200);
	
	print_subheading("bidirectional");
	ft::map<int, int>::iterator it;

	for (it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}

	print_subheading("const bidirectional");
	ft::map<int, int>::const_iterator const_it;

	for (it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}
	
	print_subheading("reverse");
	ft::map<int, int>::reverse_iterator	reverse_it;
	
	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it)
	{
		std::cout << reverse_it->first << ", " << reverse_it->second << std::endl;
	}
	
	print_subheading("const reverse");
	ft::map<int, int>::const_reverse_iterator	const_reverse_it;
	
	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it)
	{
		std::cout << reverse_it->first << ", " << reverse_it->second << std::endl;
	}
	
	print_subheading("comparisons");
	it = map.begin();
	const_it = map.begin();
	reverse_it = map.rend();
	const_reverse_it = map.rend();

	print_instructions("it == const_it");
	std::cout << (it == const_it) << std::endl;
	print_instructions("it == it");
	std::cout << (it == it) << std::endl;
	print_instructions("reverse_it == const_reverse_it");
	std::cout << (reverse_it == const_reverse_it) << std::endl;
	print_instructions("const_it == const_it");
	std::cout << (const_it == const_it) << std::endl;
}
