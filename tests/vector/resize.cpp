/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:02:46 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 21:02:56 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_resize(void)
{
	print_title(".RESIZE");
	ft::vector<float> my_vector(5, 5.1);
	std::cout << "my_vector: " << std::endl;
	displayVector(my_vector);
	print_instructions("my_vector.resize(5);");
	my_vector.resize(5);
	std::cout << "my_vector: " << std::endl;
	displayVector(my_vector);
	print_instructions("my_vector.resize(2);");
	my_vector.resize(2);
	std::cout << "my_vector: " << std::endl;
	displayVector(my_vector);
	std::cout << L_GRAY << "my_vector.resize(15);" << RESET << std::endl;
	my_vector.resize(15);
	displayVector(my_vector);
}
