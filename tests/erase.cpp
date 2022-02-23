/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:03:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 21:04:07 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_erase(void)
{
	print_title("ERASE");

	ft::vector<std::string> bocal;
	print_instructions("bocal.push_back(string) x 9");
	bocal.push_back("Kaká");
	bocal.push_back("Mari");
	bocal.push_back("Gui");
	bocal.push_back("Guiga");
	bocal.push_back("Lobão");
	bocal.push_back("Mariah");
	bocal.push_back("Clari");
	bocal.push_back("Tuca");
	bocal.push_back("Juliano");
	bocal.push_back("Vini");
	displayVector(bocal);

	print_instructions("bocal.erase(bocal.begin());");
	std::cout << "RETURN: " << *(bocal.erase(bocal.begin())) << std::endl;
	displayVector(bocal);
	print_instructions("bocal.erase(bocal.begin() + 3);");
	std::cout << "RETURN: " << *(bocal.erase(bocal.begin() + 3)) << std::endl;
	displayVector(bocal);

	print_instructions("bocal.erase(bocal.begin(), bocal.begin() + 2);");
	std::cout << "RETURN: " << *(bocal.erase(bocal.begin(), bocal.begin() + 3)) << std::endl;
	displayVector(bocal);
	print_instructions("bocal.erase(bocal.begin() + 1, bocal.begin() + 3);");
	std::cout << "RETURN: " << *(bocal.erase(bocal.begin() + 1, bocal.begin() + 3)) << std::endl;
	displayVector(bocal);
}