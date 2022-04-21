/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:35:15 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/21 16:04:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

ft::vector<int> test_push_back(void)
{
	print_title(".PUSH_BACK");

	print_instructions("ft::vector<int> integers;");
	ft::vector<int> integers;
	displayVector(integers);
	print_instructions("integers.push_back(number) x 8");
	integers.push_back(50);
	displayVector(integers);
	integers.push_back(1);
	displayVector(integers);
	integers.push_back(987);
	displayVector(integers);
	integers.push_back(1001);
	displayVector(integers);
	integers.push_back(50);
	displayVector(integers);
	integers.push_back(1);
	displayVector(integers);
	integers.push_back(987);
	displayVector(integers);
	integers.push_back(1001);
	displayVector(integers);
	return integers;
}
