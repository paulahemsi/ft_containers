/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:10:30 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 22:57:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <deque>

void	test_size(void)
{
	print_title("SIZE");
	
	{
		print_subheading("ft::vector as underlying container");
		
		ft::stack<int>	my_stack;
		
		std::cout << "Initially, my_stack.size(): " << my_stack.size() << std::endl;
		
		for (int i = 0; i < 5; i++)
			my_stack.push(i);
		std::cout << "After adding elements, my_stack.size(): " << my_stack.size() << std::endl;

		my_stack.pop();
		std::cout << "After pop an element, my_stack.size(): " << my_stack.size() << std::endl;
	}

	{
		print_subheading("std::deque as underlying container");
		
		ft::stack<int, std::deque<int> >	my_stack;
		
		std::cout << "Initially, my_stack.size(): " << my_stack.size() << std::endl;
		
		for (int i = 0; i < 5; i++)
			my_stack.push(i);
		std::cout << "After adding elements, my_stack.size(): " << my_stack.size() << std::endl;

		my_stack.pop();
		std::cout << "After pop an element, my_stack.size(): " << my_stack.size() << std::endl;
	}
	
}
