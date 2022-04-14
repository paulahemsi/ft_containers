/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_operator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:38:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/14 19:57:33 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void comparison(ft::map<char, int> &foo, ft::map<char, int> &bar)
{
	if (foo == bar)
		std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar)
		std::cout << "foo and bar are not equal" << std::endl;
}

void test_equality_operator(void)
{
	print_title("EQUALITY OPERATOR");
	
	ft::map<char, int> foo;
	ft::map<char, int> bar;
	
	print_subheading("Same size and elements");
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 100;
	bar['b'] = 200;
	comparison(foo, bar);


	print_subheading("Same size, diferent elements");
	foo['c'] = 1000;
	bar['c'] = 10000;
	comparison(foo, bar);
	
	print_subheading("diferent size and elements");
	bar['z'] = 500;
	comparison(foo, bar);
}
