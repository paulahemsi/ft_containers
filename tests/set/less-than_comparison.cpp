/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less-than_comparison.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:44:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 17:06:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T1>
void comparison(ft::set<T1> &foo, ft::set<T1> &bar)
{
	print_instructions("foo:");
	print_set(foo);
	print_instructions("bar:");
	print_set(bar);
	if (foo< bar)
		std::cout << "foo is less than bar\n";
	if (foo> bar)
		std::cout << "foo is greater than bar\n";
	if (foo<=bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar)
		std::cout << "foo is greater than or equal to bar\n";
}

void less_than_comparison(void)
{
	print_title("LESS THAN COMPARISON");

	ft::set<char> foo;
	ft::set<char> bar;
	
	print_subheading("Same size and values");
	foo.insert('a');
	foo.insert('b');
	bar.insert('a');
	bar.insert('b');
	comparison(foo, bar);

	print_subheading("Same size diferent values");
	foo.insert('c');
	bar.insert('d');
	comparison(foo, bar);

	print_subheading("same values, diferent sizes");
	bar.insert('c');
	comparison(foo, bar);
	
	print_subheading("stress test");
	{
		ft::set<int> foo = create_set_of_random_integers(500000, 7);
		ft::set<int> bar = create_set_of_random_integers(500001, 7);
		
		comparison(foo, bar);
	}
	
}
