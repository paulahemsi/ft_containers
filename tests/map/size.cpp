/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:36:23 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/08 18:27:32 by lfrasson         ###   ########.fr       */
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
	std::cout << "mymap.size() is " << mymap.size() << '\n';

	mymap.erase('x');
	std::cout << "mymap.size() is " << mymap.size() << '\n';

	mymap.erase('b');
	std::cout << "mymap.size() is " << mymap.size() << '\n';
}