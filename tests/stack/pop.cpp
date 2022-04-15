/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:38:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 13:07:31 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_pop(void)
{
	print_title("POP");

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
