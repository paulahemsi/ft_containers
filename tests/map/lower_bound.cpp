/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_bound.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:48:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/14 21:47:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void print_pair(ft::map<int, int>::const_iterator it, ft::map<int, int>::const_iterator end)
{
	if (it != end)
		std::cout << CYAN << "key " << it->first << RESET << std::endl;
	else 
		std::cout << ORANGE << "END" << RESET << std::endl;
}

void test_lower_bound(void)
{
	print_title("LOWER BOUND");

	ft::map<int, int> map = create_map_of_random_integers(100000, 22);
	ft::map<int, int>::iterator it_end = map.end();
	print_instructions("map.lower_bound(5)");
	print_pair(map.lower_bound(5), it_end);
	print_instructions("map.lower_bound(170)");
	print_pair(map.lower_bound(170), it_end);
	print_instructions("map.lower_bound(777)");
	print_pair(map.lower_bound(777), it_end);
	print_instructions("map.lower_bound(77898)");
	print_pair(map.lower_bound(77898), it_end);

}
