/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:55:56 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/13 21:00:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_swap(void)
{
	print_title("SWAP");
	
	print_subheading("member function");
	{
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
	print_subheading("non-member function");
	{
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		swap(foo,bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	}
}
