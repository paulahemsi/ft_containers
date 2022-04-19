/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_operator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:20:05 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 22:40:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>
#include <list>
#include <deque>

template <typename T>
static void comparison(T &foo, T &bar)
{
	if (foo == bar)
		std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar)
		std::cout << "foo and bar are not equal" << std::endl;
}

template <typename T>
void add_and_compare(T &foo, T &bar)
{
	print_subheading("Same size and elements");
	foo.push('a');
	foo.push('b');
	bar.push('a');
	bar.push('b');
	comparison(foo, bar);

	print_subheading("Same size, diferent elements");
	foo.push('c');
	bar.push('d');
	comparison(foo, bar);
	
	print_subheading("diferent size and elements");
	bar.push('z');
	comparison(foo, bar);
}

void test_equality_operator(void)
{
	print_title("EQUALITY OPERATOR");

	{
		print_subheading("std vector as underlying container");
		ft::stack<char, std::vector<char> > foo;
		ft::stack<char, std::vector<char> > bar;
		add_and_compare(foo, bar);
	}

	{
		print_subheading("ft::vector as underlying container");
		ft::stack<char> foo;
		ft::stack<char> bar;
		add_and_compare(foo, bar);
	}

	{
		print_subheading("std list as underlying container");
		ft::stack<char, std::list<char> > foo;
		ft::stack<char, std::list<char> > bar;
		add_and_compare(foo, bar);
	}

	{
		print_subheading("std deque as underlying container");
		ft::stack<char, std::deque<char> > foo;
		ft::stack<char, std::deque<char> > bar;
		add_and_compare(foo, bar);
	}
}
