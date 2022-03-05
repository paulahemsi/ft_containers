/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:58:40 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/22 19:59:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_constructors(void)
{
	print_title("CONSTRUCTORS");

	print_instructions("ft::vector<int> emptyVector;");
	ft::vector<int> emptyVector;
	displayVector(emptyVector);

	print_instructions("ft::vector<int> fourElements(4);");
	ft::vector<int> fourElements(4);
	displayVector(fourElements);

	print_instructions("ft::vector<int> tenElements (10);");
	ft::vector<int> tenElements(10);
	displayVector(tenElements);

	print_instructions("ft::vector<int> tenElement90 (10, 90);");
	ft::vector<int> tenElement90(10, 90);
	displayVector(tenElement90);

	print_instructions("ft::vector<int> copyVector (tenElement90);");
	ft::vector<int> copyVector(tenElement90);
	displayVector(copyVector);

	print_instructions("ft::vector<int> partialCopy (tenElements.begin(), tenElements.begin() + 5);");
	ft::vector<int> partialCopy(tenElements.begin(),
	tenElements.begin() + 5);
	displayVector(partialCopy);
}
