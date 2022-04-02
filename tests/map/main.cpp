/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:16:02 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/01 23:29:09 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void test_constructors(void)
{
	print_title("CONSTRUCTORS");
	
	ft::map<int, int>	my_map;
	const ft::pair<const int, int>	my_pair =  ft::make_pair(1, 1);


	my_map.insert(my_pair);
	
	
}

int main(void)
{
	print_title(VERSION);
	std::cout.setf(std::ios::boolalpha);
	test_pair();
	test_constructors();
}
