/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_operator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:38:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 16:46:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void comparison(ft::set<int> &foo, ft::set<int> &bar)
{
	if (foo == bar)
		std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar)
		std::cout << "foo and bar are not equal" << std::endl;
}

void test_equality_operator(void)
{
	print_title("EQUALITY OPERATOR");
	
	ft::set<int> foo;
	ft::set<int> bar;
	
	print_subheading("Same size and elements");
	foo.insert(100);
	foo.insert(200);
	bar.insert(100);
	bar.insert(200);
	comparison(foo, bar);


	print_subheading("Same size, diferent elements");
	foo.insert(1000);
	bar.insert(10000);
	comparison(foo, bar);
	
	print_subheading("diferent size and elements");
	bar.insert(500);
	comparison(foo, bar);
}
