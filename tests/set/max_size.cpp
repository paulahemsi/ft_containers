/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:39:22 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/15 17:08:25 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void max_size(void)
{
	int i;
	ft::set<int> myset;

	print_title("MAX_SIZE");

	if (myset.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			myset.insert(0);
		std::cout << "The set contains 1000 elements.\n";
	}
	else
		std::cout << "The set could not hold 1000 elements.\n";

}
