/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:38:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/18 22:55:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <list>

void test_pop(void)
{
	print_title("POP");

	{
		print_subheading("ft vector as underlying container");
		ft::stack<int> stack;
		stack.push(4);
		std::cout << "Top element: " << stack.top() << '\n';
		stack.push(5);
		std::cout << "Top element: " << stack.top() << '\n';
		stack.push(6);
		std::cout << "Top element: " << stack.top() << '\n';
		stack.push(7);
		std::cout << "Top element: " << stack.top() << '\n';
		
		while (stack.size() != 1)
		{
			stack.pop();
			std::cout << "Top element: " << stack.top() << '\n';
		}
	}

	{
		print_subheading("std list as underlying container");
		ft::stack<int, std::list<int> > stack;
		stack.push(4);
		std::cout << "Top element: " << stack.top() << '\n';
		stack.push(5);
		std::cout << "Top element: " << stack.top() << '\n';
		stack.push(6);
		std::cout << "Top element: " << stack.top() << '\n';
		stack.push(7);
		std::cout << "Top element: " << stack.top() << '\n';
		
		while (stack.size() != 1)
		{
			stack.pop();
			std::cout << "Top element: " << stack.top() << '\n';
		}
	}

}
