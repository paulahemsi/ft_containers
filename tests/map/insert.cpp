/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:01:21 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/06 22:07:26 by phemsi-a         ###   ########.fr       */
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

void	test_insert(void)
{
	print_title("INSERT");
	
	ft::map<int, int>	map;

	insert(map, ft::make_pair(1, 1110));
	insert(map, ft::make_pair(2, 222));	
	insert(map, ft::make_pair(1, 1));	
	insert(map, ft::make_pair(2, 2));	
}
