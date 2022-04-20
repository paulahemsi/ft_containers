/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:40:33 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
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

	std::cout << "mymap['a'] is " << map['a'] << std::endl;
	std::cout << "mymap['b'] is " << map['b'] << std::endl;
	std::cout << "mymap['c'] is " << map['c'] << std::endl;
	std::cout << "mymap['d'] is " << map['d'] << std::endl;

	std::cout << "mymap now contains " << map.size() << " elements.\n";
}
