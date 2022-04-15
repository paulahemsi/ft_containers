/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:55:56 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 17:12:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_swap(void)
{
	print_title("SWAP");
	
	print_subheading("member function");
	{
		ft::set<char> foo;
		ft::set<char> bar;

		foo.insert('x'); 
		foo.insert('y'); 

		bar.insert('a');
		bar.insert('b');
		bar.insert('c');

		std::cout << "foo -> size " << foo.size() << " -> contains:" << std::endl;
		print_set(foo);
		std::cout << "bar -> size " << bar.size() << " -> contains:" << std::endl;
		print_set(bar);

		ft::set<char>::iterator it1 = foo.begin();
		ft::set<char>::iterator it2 = bar.begin();

		std::cout << "it1: " << *it1 << std::endl;
		std::cout << "it2: " << *it2<< std::endl;
		std::cout << std::endl;

		print_instructions("foo.swap(bar);");
		foo.swap(bar);

		std::cout << "foo -> size " << foo.size() << " -> contains:" << std::endl;
		print_set(foo);
		std::cout << "bar -> size " << bar.size() << " -> contains:" << std::endl;
		print_set(bar);
		
		std::cout << "it1: " << *it1 << std::endl;
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << std::endl;
	}
	print_subheading("non-member function");
	{
		ft::set<int> foo,bar;

		foo.insert(100);
		foo.insert(200);

		bar.insert(11);
		bar.insert(22);
		bar.insert(33);

		std::cout << "foo -> size " << foo.size() << " -> contains:" << std::endl;
		print_set(foo);
		std::cout << "bar -> size " << bar.size() << " -> contains:" << std::endl;
		print_set(bar);

		ft::set< int>::iterator it1 = foo.begin()++;
		ft::set< int>::iterator it2 = bar.begin()++;

		std::cout << "it1: " << *it1 << std::endl;
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << std::endl;

		print_instructions("swap(foo,bar);");

		swap(foo,bar);

		std::cout << "foo -> size " << foo.size() << " -> contains:" << std::endl;
		print_set(foo);
		std::cout << "bar -> size " << bar.size() << " -> contains:" << std::endl;
		print_set(bar);
		
		std::cout << "it1: " << *it1 << std::endl;
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << std::endl;
	}
}
