/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:16:02 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/08 21:58:51 by phemsi-a         ###   ########.fr       */
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
	
	print_subheading("bidirectional");
	ft::map<int, int>::iterator it;

	for (it = map.begin(); it != map.end(); ++it) {
 	   std::cout << it->first << ", " << it->second << '\n';
	}

	print_subheading("reverse");
	ft::map<int, int>::reverse_iterator	reverse_it;
	
	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it) {
 	std::cout << reverse_it->first << ", " << reverse_it->second << '\n';
	}
	

	// ft::map<int, int>::iterator test = map.begin();
	// std::cout << "BEGIN: ";
	// std::cout << test->first << std::endl;
	// test--;
	// std::cout << "--: ";
	// std::cout << test->first << std::endl;
	// test++;
	// std::cout << "++: ";
	// std::cout << test->first << std::endl;

	// test = map.begin();
	// std::cout << "BEGIN: ";
	// std::cout << test->first << std::endl;
	// test++;
	// std::cout << "++: ";
	// std::cout << test->first << std::endl;
	// test--;
	// std::cout << "--: ";
	// std::cout << test->first << std::endl;

	// ft::map<int, int>::iterator test_end = map.end();
	// std::cout << "END: ";
	// std::cout << test_end->first << std::endl;
	// test_end--;
	// std::cout << "--: ";
	// std::cout << test_end->first << std::endl;
	// test_end++;
	// std::cout << "++: ";
	// std::cout << test_end->first << std::endl;

	// ft::map<int, int>::reverse_iterator test_rend = map.rend();
	// std::cout << "REND: ";
	// std::cout << test_rend->first << std::endl;
	// test_rend--;
	// std::cout << "--: ";
	// std::cout << test_rend->first << std::endl;
	// test_rend++;
	// std::cout << "++: ";
	// std::cout << test_rend->first << std::endl;
	
	// ft::map<int, int>::reverse_iterator test_rbegin = map.rbegin();
	// std::cout << "RBEGIN: ";
	// std::cout << test_rbegin->first << std::endl;
	// test_rbegin--;
	// std::cout << "--: ";
	// std::cout << test_rbegin->first << std::endl;
	// test_rbegin++;
	// std::cout << "++: ";
	// std::cout << test_rbegin->first << std::endl;
	
	// test_rbegin = map.rbegin();
	// std::cout << "RBEGIN: ";
	// std::cout << test_rbegin->first << std::endl;
	// test_rbegin++;
	// std::cout << "++: ";
	// std::cout << test_rbegin->first << std::endl;
	// test_rbegin--;
	// std::cout << "--: ";
	// std::cout << test_rbegin->first << std::endl;
	
}

int main(void)
{
	print_title(VERSION);
	std::cout.setf(std::ios::boolalpha);
	test_pair();
	test_constructors();
	test_iterators();
	test_find();
	test_get_allocator();
	test_insert();
	test_erase();
	test_access_element_operator();
	test_size();
	test_lower_bound();
	test_upper_bound();
}
