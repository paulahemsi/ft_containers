/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less-than_comparison.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:44:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/19 20:30:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T1, typename T2>
void comparison(ft::map<T1, T2> &foo, ft::map<T1, T2> &bar)
{
	if (foo< bar)
		std::cout << "foo is less than bar\n";
	if (foo> bar)
		std::cout << "foo is greater than bar\n";
	if (foo<=bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar)
		std::cout << "foo is greater than or equal to bar\n";
}

template <typename T1, typename T2>
void print_maps(ft::map<T1, T2> &foo, ft::map<T1, T2> &bar)
{
	print_instructions("foo:");
	print_map(foo);
	print_instructions("bar:");
	print_map(bar);
}

void less_than_comparison(void)
{
	print_title("LESS THAN COMPARISON");

	ft::map<char, int> foo;
	ft::map<char, int> bar;
	
	print_subheading("Same size, keys and values");
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 100;
	bar['b'] = 200;
	print_maps(foo, bar);
	comparison(foo, bar);

	print_subheading("Same size, same keys, diferent values");
	bar['b'] = 201;
	print_maps(foo, bar);
	comparison(foo, bar);

	print_subheading("Same size, same values, diferent keys");
	foo['b'] = 201;
	foo['c'] = 300;
	bar['d'] = 300;
	print_maps(foo, bar);
	comparison(foo, bar);
	
	print_subheading("same keys and values, diferent sizes");
	bar.erase('d');
	bar['c'] = 300;
	bar['z'] = 500;
	print_maps(foo, bar);
	comparison(foo, bar);
	
	print_subheading("stress test");
	{
		ft::map<int, int> foo = create_map_of_random_integers(500000, 7);
		ft::map<int, int> bar = create_map_of_random_integers(500001, 7);
		
		comparison(foo, bar);
	}
	
}
