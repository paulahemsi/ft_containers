/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:48:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 17:07:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void print_pair(ft::set<int>::const_iterator it, ft::set<int>::const_iterator end)
{
	if (it != end)
		std::cout << CYAN << *it << RESET << std::endl;
	else 
		std::cout << ORANGE << "END" << RESET << std::endl;
}

void test_lower_bound(void)
{
	print_title("LOWER BOUND");

	ft::set<int> set = create_set_of_random_integers(100000, 22);
	ft::set<int>::iterator it_end = set.end();
	print_instructions("set.lower_bound(5)");
	print_pair(set.lower_bound(5), it_end);
	print_instructions("set.lower_bound(170)");
	print_pair(set.lower_bound(170), it_end);
	print_instructions("set.lower_bound(777)");
	print_pair(set.lower_bound(777), it_end);
	print_instructions("set.lower_bound(77898)");
	print_pair(set.lower_bound(77898), it_end);

}
