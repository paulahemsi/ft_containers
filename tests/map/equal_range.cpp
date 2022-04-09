/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:34:45 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/09 16:02:37 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_equal_range(void)
{
	print_title("EQUAL RANGE");
	print_title("char - int");

	ft::map<char,int> mymap;

	print_instructions("mymap['a']=10;\nmymap['b']=20;\nmymap['c']=30;);\n");

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	print_subheading("lower bound points to: ");
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	print_subheading("upper bound points to: ");
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	print_title("int - int");

	ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator> ret_int;
	ft::map<int, int> map = create_map_of_random_integers(400, 1);
	ret_int = map.equal_range(977);

	print_subheading("lower bound points to: ");
	std::cout << ret_int.first->first << " => " << ret_int.first->second << '\n';

	print_subheading("upper bound points to: ");
	std::cout << ret_int.second->first << " => " << ret_int.second->second << '\n';

	ret_int = map.equal_range(500);

	print_subheading("lower bound points to: ");
	std::cout << ret_int.first->first << " => " << ret_int.first->second << '\n';

	print_subheading("upper bound points to: ");
	std::cout << ret_int.second->first << " => " << ret_int.second->second << '\n';

}