/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:16:02 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/03 18:15:49 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void test_constructors(void)
{
	print_title("CONSTRUCTORS");
	
	ft::map<int, int>	my_map;
	const ft::pair<const int, int>	my_pair =  ft::make_pair(1, 1);


	my_map.insert(my_pair);
	my_map.begin();
	
}

static void	test_iterators(void)
{
	print_title("ITERATORS");
	
	ft::map<int, int> map = create_map_of_random_integers(8, 200);
	
	ft::map<int, int>::iterator it;

	for (it = map.begin(); it != map.end(); ++it) {
 	   std::cout << it->first << ", " << it->second << '\n';
	}
 	std::cout << it->first << ", " << it->second << '\n';
}

int main(void)
{
	print_title(VERSION);
	std::cout.setf(std::ios::boolalpha);
	test_pair();
	test_constructors();
	test_iterators();
}
