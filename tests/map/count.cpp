/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:30:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/13 21:51:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"


void test_count(void)
{
	print_title("COUNT");

	ft::map<std::string, float> map;
	map.insert(ft::make_pair("two and a half", 2.5));
	map.insert(ft::make_pair("one and a half", 1.5));
	map.insert(ft::make_pair("nine and a half", 9.5));
	map.insert(ft::make_pair("four and a half", 4.5));

	print_instructions("map.count(\"one and a half\")");
	std::cout << map.count("one and a half") << std::endl;
	print_instructions("map.count(\"nine and a half\")");
	std::cout << map.count("nine and a half") << std::endl;
	print_instructions("map.count(\"four and a half\")");
	std::cout << map.count("four and a half") << std::endl;
	print_instructions("map.count(\"blablablabla\")");
	std::cout << map.count("blablablabla") << std::endl;
	
}
