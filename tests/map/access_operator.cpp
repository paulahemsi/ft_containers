/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:40:33 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/08 15:04:54 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <string>

void	test_access_element_operator(void)
{
	print_title("ACCESS ELEMENT OPERATOR");
	
	ft::map<char,std::string> map;	
	map['a']="an element";
	map['b']="another element";
	map['c']=map['b'];

	std::cout << "mymap['a'] is " << map['a'] << '\n';
	std::cout << "mymap['b'] is " << map['b'] << '\n';
	std::cout << "mymap['c'] is " << map['c'] << '\n';
	std::cout << "mymap['d'] is " << map['d'] << '\n';

	std::cout << "mymap now contains " << map.size() << " elements.\n";
}