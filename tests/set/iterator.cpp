/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:01:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 17:02:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_iterators(void)
{
	print_title("ITERATORS");
	
	ft::set<int> set = create_set_of_random_integers(8, 200);
	
	print_subheading("bidirectional");
	ft::set<int>::iterator it;

	for (it = set.begin(); it != set.end(); ++it)
	{
		std::cout << *it << '\n';
	}

	print_subheading("const bidirectional");
	ft::set<int>::const_iterator const_it;

	for (it = set.begin(); it != set.end(); ++it)
	{
		std::cout << *it << '\n';
	}
	
	print_subheading("reverse");
	ft::set<int>::reverse_iterator	reverse_it;
	
	for (reverse_it = set.rbegin(); reverse_it != set.rend(); ++reverse_it)
	{
		std::cout << *reverse_it << '\n';
	}
	
	print_subheading("const reverse");
	ft::set<int>::const_reverse_iterator	const_reverse_it;
	
	for (reverse_it = set.rbegin(); reverse_it != set.rend(); ++reverse_it)
	{
		std::cout << *reverse_it << '\n';
	}
}
