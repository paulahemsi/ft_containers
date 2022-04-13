/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:39:22 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/12 21:12:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void max_size(void)
{
	int i;
	ft::map<int,int> mymap;

	print_title("MAX_SIZE");

	if (mymap.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			mymap[i] = 0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else
		std::cout << "The map could not hold 1000 elements.\n";

}
