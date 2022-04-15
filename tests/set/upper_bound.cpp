/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:48:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 17:13:26 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void print_value(ft::set<int>::const_iterator it, ft::set<int>::const_iterator end)
{
	if (it != end)
		std::cout << CYAN << "value " << *it << RESET << std::endl;
	else 
		std::cout << ORANGE << "END" << RESET << std::endl;
}

void test_upper_bound(void)
{
	print_title("UPPER BOUND");

	ft::set<int> set = create_set_of_random_integers(100000, 22);
	ft::set<int>::iterator it_end = set.end();
	print_instructions("set.upper_bound(5)");
	print_value(set.upper_bound(5), it_end);
	print_instructions("set.upper_bound(170)");
	print_value(set.upper_bound(170), it_end);
	print_instructions("set.upper_bound(777)");
	print_value(set.upper_bound(777), it_end);
	print_instructions("set.upper_bound(77898)");
	print_value(set.upper_bound(77898), it_end);

}
