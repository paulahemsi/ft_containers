/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:19:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/22 16:02:23 by lfrasson         ###   ########.fr       */
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
	
	ft::map<char,int> first_map;
	print_instructions("Print map construct with default\n");
	print_map(first_map);

	first_map['a'] = 10;
	first_map['b'] = 30;
	first_map['c'] = 50;
	first_map['d'] = 70;

	print_instructions("Print map filled with 4 pairs");
	print_map(first_map);
	
	ft::map<char,int> *second_map = new ft::map<char, int>(first_map.begin(),first_map.end());
	print_instructions("Print map construct with range");
	print_map(*second_map);

	ft::map<char,int> third_map (*second_map);
	delete second_map;
	print_instructions("Print map construct with copy");
	print_map(third_map);

	ft::map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
}