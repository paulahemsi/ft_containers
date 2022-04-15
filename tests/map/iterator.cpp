/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:01:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/14 21:49:07 by lfrasson         ###   ########.fr       */
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
		std::cout << it->first << ", " << it->second << '\n';
	}

	print_subheading("const bidirectional");
	ft::map<int, int>::const_iterator const_it;

	for (it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->first << ", " << it->second << '\n';
	}
	
	print_subheading("reverse");
	ft::map<int, int>::reverse_iterator	reverse_it;
	
	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it)
	{
		std::cout << reverse_it->first << ", " << reverse_it->second << '\n';
	}
	
	print_subheading("const reverse");
	ft::map<int, int>::const_reverse_iterator	const_reverse_it;
	
	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it)
	{
		std::cout << reverse_it->first << ", " << reverse_it->second << '\n';
	}
}