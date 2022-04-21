/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:01:21 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 12:19:42 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void print(ft::pair<ft::set<int>::iterator, bool> insert_return)
{
	int value = *(insert_return.first);
	
	if (insert_return.second)
	{
		std::cout << CYAN << "Success inserting: "
					<< "(" << value << ")"
					<< RESET << std::endl;
		return ;
	}
	std::cout << ORANGE
				<< "Fail inserting because set already have pair:"
				<< "(" << value << ")"
				<< RESET << std::endl;
}

static void insert(ft::set<int> &set, int value)
{
	ft::pair<ft::set<int>::iterator, bool>	insert_return;
	
	std::cout << "insert number ("
				<< value << ") to set"
				<< std::endl;
	insert_return = set.insert(value);
	print(insert_return);	
}

static void insert_single_element(void)
{
	print_title("INSERT SINGLE ELEMENT");
	
	ft::set<int>	set;

	insert(set, 1110);
	insert(set, 222);	
	insert(set, 1);	
	insert(set, 2);	
}

static void insert(void)
{
	ft::set<int> myset;
	
	// first insert function version (single parameter):
	myset.insert(100);
	ft::set<int>::iterator iter = myset.begin();
	std::cout << "\niterator: " << *iter << std::endl;
	myset.insert(200);
	
	ft::pair<ft::set<int>::iterator,bool> ret;
	ret = myset.insert (500);
	if (ret.second==false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << *(ret.first) << std::endl;
	}
	std::cout << "\niterator: " << *iter << std::endl;
	
	print_title("INSERT WITH HINT POSITION");
	// second insert function version (with hint position):
	ft::set<int>::iterator it = myset.begin();
	myset.insert (it, 300);  // max efficiency inserting
	myset.insert (it, 400);  // no max efficiency inserting
	std::cout << "\niterator: " << *iter << std::endl;

	std::cout << "myset contains:\n";
	for (it=myset.begin(); it!=myset.end(); ++it)
    	std::cout << *it << std::endl;

	print_title("INSERT WITH RANGE");
	
	// third insert function version (range insertion):
	ft::set<int> anotherset;
	anotherset.insert(myset.begin(), myset.find('c'));
	
	// showing contents:
	std::cout << "myset contains:\n";
	for (it = myset.begin(); it != myset.end(); ++it)
    	std::cout << *it << std::endl;

	std::cout << "anotherset contains:\n";
	for (it = anotherset.begin(); it != anotherset.end(); ++it)
    	std::cout << *it << std::endl;
	std::cout << "\niterator: " << *iter << std::endl;
}

void	test_insert(void)
{
	insert_single_element();
	insert();
}
