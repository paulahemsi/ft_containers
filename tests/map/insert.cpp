/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:01:21 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 12:17:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void print(ft::pair<ft::map<int, int>::iterator, bool> insert_return)
{
	ft::pair<int, int> pair = *(insert_return.first);
	
	if (insert_return.second)
	{
		std::cout << CYAN << "Success inserting: "
					<< "(" << pair.first << ", " << pair.second << ")"
					<< RESET << std::endl;
		return ;
	}
	std::cout << ORANGE
				<< "Fail inserting because map already have pair:"
				<< "(" << pair.first << ", " << pair.second << ")"
				<< RESET << std::endl;
}

static void insert(ft::map<int, int> &map, ft::pair<const int, int> pair)
{
	ft::pair<ft::map<int, int>::iterator, bool>	insert_return;
	
	std::cout << "insert pair ("
				<< pair.first << ", "
				<< pair.second << ") to map"
				<< std::endl;
	insert_return = map.insert(pair);
	print(insert_return);	
}

static void insert_single_element(void)
{
	print_title("INSERT SINGLE ELEMENT");
	
	ft::map<int, int>	map;

	insert(map, ft::make_pair(1, 1110));
	insert(map, ft::make_pair(2, 222));	
	insert(map, ft::make_pair(1, 1));	
	insert(map, ft::make_pair(2, 2));	
}

static void insert(void)
{
	ft::map<char,int> mymap;
	
	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	std::cout << "insert pair ('a',100) to map" << std::endl;
	
	ft::map<char, int>::iterator iter = mymap.begin();
	std::cout << "\niterator: " << iter->first << std::endl;
	
	mymap.insert ( ft::pair<char,int>('z',200) );
	std::cout << "insert pair ('z',200) to map" << std::endl;
	
	
	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second == false)
	{
		std::cout << ORANGE << "Fail inserting ('z',500) because element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << RESET << std::endl;
	}
	std::cout << "\niterator: " << iter->first << std::endl;
	
	print_title("INSERT WITH HINT POSITION");
	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
	std::cout << "\niterator: " << iter->first << std::endl;

	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;

	print_title("INSERT WITH RANGE");
	
	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));
	
	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "\niterator: " << iter->first << std::endl;
}

void	test_insert(void)
{
	insert_single_element();
	insert();
}
