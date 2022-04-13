/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:55:56 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/12 21:23:06 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_swap(void)
{
	print_title("SWAP");
	
	ft::map<char, int> foo;
	ft::map<char, int> bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	std::cout << "foo -> size " << foo.size() << " -> contains:" << std::endl;
	print_map(foo);
	std::cout << "bar -> size " << bar.size() << " -> contains:" << std::endl;
	print_map(bar);

	ft::map<char, int>::iterator it1 = foo.begin();
	ft::map<char, int>::iterator it2 = bar.begin();

	std::cout << "it1: " << it1->first << ", " << it1->second << std::endl;
	std::cout << "it2: " << it2->first << ", " << it2->second << std::endl;
	std::cout << std::endl;

	print_instructions("foo.swap(bar);");
	foo.swap(bar);

	std::cout << "foo -> size " << foo.size() << " -> contains:" << std::endl;
	print_map(foo);
	std::cout << "bar -> size " << bar.size() << " -> contains:" << std::endl;
	print_map(bar);
	
	std::cout << "it1: " << it1->first << ", " << it1->second << std::endl;
	std::cout << "it2: " << it2->first << ", " << it2->second << std::endl;
	std::cout << std::endl;
}