/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:41:14 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 11:48:27 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_push(void)
{
	print_title("PUSH");
	
	ft::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);
	
	std::cout << "After adding elements, mystack.size(): " << mystack.size() << std::endl;	
	std::cout << "Popping out elements...";
	// while (!mystack.empty())
	// {
	// 	std::cout << ' ' << mystack.top();
	// 	mystack.pop();
	// }
	// std::cout << std::endl;	
}