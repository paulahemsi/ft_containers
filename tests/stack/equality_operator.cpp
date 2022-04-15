/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_operator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:20:05 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 12:20:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void comparison(ft::stack<char> &foo, ft::stack<char> &bar)
{
	if (foo == bar)
		std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar)
		std::cout << "foo and bar are not equal" << std::endl;
}

void test_equality_operator(void)
{
	print_title("EQUALITY OPERATOR");
	
	ft::stack<char> foo;
	ft::stack<char> bar;
	
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