/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:00:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/18 22:49:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>
#include <list>
#include <deque>

template <class Container>
void reportStackSize(Container & container)
{
	std::cout << container.size() << " elements on stack\n";
}

template <class Container>
void reportStackTop(Container & container)
{
	std::cout << "Top element: " << container.top() << '\n';
}

template <class Container>
void do_tests(Container & container)
{
	container.push(2);
	container.push(6);
	container.push(51);

	reportStackSize(container);
	reportStackTop(container);

	reportStackSize(container);
	container.pop();

	reportStackSize(container);
	reportStackTop(container);
}

void test_top(void)
{
	print_title("TOP");

	{
		print_subheading("ft::vector as underlying container");
		ft::stack<int> container;
		do_tests(container);
	}

	{
		print_subheading("std vector as underlying container");
		ft::stack<char, std::vector<char> > container;
		do_tests(container);
	}

	{
		print_subheading("std list as underlying container");
		ft::stack<char, std::list<char> > container;
		do_tests(container);
	}

	{
		print_subheading("std deque as underlying container");
		ft::stack<char, std::deque<char> > container;
		do_tests(container);
	}
}
