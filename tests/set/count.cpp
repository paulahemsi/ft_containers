/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:30:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 16:39:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"


void test_count(void)
{
	print_title("COUNT");

	ft::set<std::string> set;
	set.insert("two and a half");
	set.insert("one and a half");
	set.insert("nine and a half");
	set.insert("four and a half");

	print_instructions("set.count(\"one and a half\")");
	std::cout << set.count("one and a half") << std::endl;
	print_instructions("set.count(\"nine and a half\")");
	std::cout << set.count("nine and a half") << std::endl;
	print_instructions("set.count(\"four and a half\")");
	std::cout << set.count("four and a half") << std::endl;
	print_instructions("set.count(\"blablablabla\")");
	std::cout << set.count("blablablabla") << std::endl;
	
}
