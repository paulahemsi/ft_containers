/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:36:23 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/19 20:42:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	test_size(void)
{
	print_title("SIZE");
	
	ft::map<char,int> mymap;
	
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;
	std::cout << "mymap.size() is " << mymap.size() << std::endl;

	mymap.erase('x');
	std::cout << "mymap.size() is " << mymap.size() << std::endl;

	mymap.erase('b');
	std::cout << "mymap.size() is " << mymap.size() << std::endl;
}
