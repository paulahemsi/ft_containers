/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:13:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 11:18:05 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <deque>

void test_canonical_form(void)
{
	print_title("CANONICAL FORM");

	ft::stack<int> c1;
	ft::stack<int> c2(c1);
	ft::stack<int, std::deque<int> > c3;
	ft::stack<int, std::deque<int> > c4;
	c4 = c3;
}
