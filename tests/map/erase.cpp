/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:28:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/06 22:41:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_erase(void)
{
	print_title("ERASE");

	ft::map<float, float> map = create_map_of_floats(3);
	print_instructions("find 0.1?");
	print_found(map.find(0.1), map.end());
	print_instructions("0.1 erased");
	map.erase(map.find(0.1));
	print_instructions("find 0.1?");
	print_found(map.find(0.1), map.end());
}
