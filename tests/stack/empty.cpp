/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:56:31 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 22:44:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <deque>
#include <list>

void	test_empty(void)
{
	print_title("EMPTY");

	print_subheading("ft::vector as underlying container");
	{
		ft::stack<int> mystack;

		int sum(0);

		for (int i = 1; i <= 10000; i++)
			mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		
		std::cout << "total: " << sum << std::endl;
	}
	print_subheading("std deque as underlying container");
	{
		ft::stack<int, std::deque<int> > mystack;

		int sum(0);

		for (int i = 1; i <= 10000; i++)
			mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		
		std::cout << "total: " << sum << std::endl;
	}
	print_subheading("std list as underlying container");
	{
		ft::stack<int, std::list<int> > mystack;

		int sum(0);

		for (int i = 1; i <= 10000; i++)
			mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		
		std::cout << "total: " << sum << std::endl;
	}
}
