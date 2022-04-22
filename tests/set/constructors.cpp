/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:19:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/22 16:05:29 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

bool fncomp (char lhs, char rhs)
{
	return lhs < rhs;
}

struct classcomp
{
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs < rhs;
	}
};

void test_constructors(void)
{
	print_title("CONSTRUCTORS");
	
	ft::set<int> first_set;
	print_instructions("Print set construct with default\n");
	print_set(first_set);

	first_set.insert(10);
	first_set.insert(30);
	first_set.insert(50);
	first_set.insert(70);

	print_instructions("Print set filled with 4 pairs");
	print_set(first_set);
	
	ft::set<int> *second_set = new ft::set<int>(first_set.begin(),first_set.end());
	print_instructions("Print set construct with range");
	print_set(*second_set);

	ft::set<int> third_set (*second_set);
	delete second_set;
	print_instructions("Print set construct with copy");
	print_set(third_set);

	ft::set<int, classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char, char) = fncomp;
	ft::set<char, bool(*)(char, char)> fifth (fn_pt); // function pointer as Compare
}
