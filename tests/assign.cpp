/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:46:30 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 20:46:39 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_assign(void)
{
	print_title(".ASSIGN");
	print_instructions("ft::vector<int> integers;");
	ft::vector<int> integers;
	displayVector(integers);
	std::cout << L_GRAY << "integers.assign(2, 22);" << RESET << std::endl;
	integers.assign(2, 22);
	displayVector(integers);
	print_instructions("integers.push_back(number) x 3");
	integers.push_back(50);
	integers.push_back(1);
	integers.push_back(987);
	displayVector(integers);
	std::cout << L_GRAY << "integers.assign(3, 33);" << RESET << std::endl;
	integers.assign(3, 33);
	displayVector(integers);
	print_instructions("integers.push_back(number) x 8");
	integers.push_back(50);
	integers.push_back(1);
	integers.push_back(987);
	integers.push_back(1001);
	integers.push_back(50);
	integers.push_back(1);
	integers.push_back(987);
	integers.push_back(1001);
	displayVector(integers);
	std::cout << L_GRAY << "integers.assign(4, 44);" << RESET << std::endl;
	integers.assign(4, 44);
	displayVector(integers);

	ft::vector<int> integers2;
	print_instructions("integers2.push_back(number) x 8");
	integers2.push_back(50);
	integers2.push_back(1);
	integers2.push_back(987);
	integers2.push_back(1001);
	integers2.push_back(50);
	integers2.push_back(1);
	integers2.push_back(987);
	integers2.push_back(1001);
	displayVector(integers2);

	ft::vector<int>::iterator it = integers2.begin();
	print_instructions("integers.assign(it, it + 3);");
	integers.assign(it, it + 3);
	displayVector(integers);

	ft::vector<int> smallVector(1);
	displayVector(smallVector);
	print_instructions("smallVector.assign(it, it + 7);");
	smallVector.assign(it, it + 7);
	displayVector(smallVector);
}
