/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:03 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 20:50:10 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_clear(void)
{
	print_title("CLEAR");

	ft::vector<float> floats;
	print_instructions("floats.push_back(number) x 9");
	floats.push_back(59.57);
	floats.push_back(9.57);
	floats.push_back(989.57);
	floats.push_back(1009.57);
	floats.push_back(59.57);
	floats.push_back(9.57);
	floats.push_back(989.57);
	floats.push_back(1009.57);
	floats.push_back(1234.567);
	displayVector(floats);

	print_instructions("floats.clear();");
	floats.clear();
	displayVector(floats);
	print_instructions("floats.push_back(9.57);");
	floats.push_back(9.57);
	displayVector(floats);
}