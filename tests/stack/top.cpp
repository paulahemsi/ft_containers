/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:00:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 12:11:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void reportStackSize(const ft::stack<int>& s)
{
	std::cout << s.size() << " elements on stack\n";
}
 
void reportStackTop(const ft::stack<int>& s)
{
	std::cout << "Top element: " << s.top() << '\n';
}

void test_top(void)
{
	print_title("TOP");

	ft::stack<int> s;
	s.push(2);
	s.push(6);
	s.push(51);

	reportStackSize(s);
	reportStackTop(s);

	reportStackSize(s);
	s.pop();

	reportStackSize(s);
	reportStackTop(s);
}
