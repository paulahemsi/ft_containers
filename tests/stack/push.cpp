/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:41:14 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 23:10:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>
#include <list>
#include <deque>

template <class Container>
void do_test(Container & mystack)
{
	for (int i = 0; i < 500; ++i)
	mystack.push(i);
	std::cout << "After adding elements, mystack.size(): " << mystack.size() << std::endl;	
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << std::endl;	
}

void	test_push(void)
{
	print_title("PUSH");
	
	{
		print_subheading("std vector as underlying container");
		ft::stack<int, std::vector<int> > mystack;
		do_test(mystack);
	}

	{
		print_subheading("ft::vector as underlying container");
		ft::stack<int> mystack;	
		do_test(mystack);
	}

	{
		print_subheading("std list as underlying container");
		ft::stack<int, std::list<int> > mystack;
		do_test(mystack);
	}

	{
		print_subheading("std deque as underlying container");
		ft::stack<int, std::deque<int> > mystack;
		do_test(mystack);
	}
	

}
