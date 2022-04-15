/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:56:31 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 12:02:15 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_empty(void)
{
	print_title("EMPTY");

	ft::stack<int> mystack;

	int sum(0);

	for (int i = 1; i <= 10; i++)
		mystack.push(i);

	while (!mystack.empty())
	{
		// sum += mystack.top();
		mystack.pop();
	}
	
	std::cout << "total: " << sum << std::endl;
}