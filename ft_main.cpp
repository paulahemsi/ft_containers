/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/12/12 11:50:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"

static void testDisplay(ft::vector<int>& vector_)
{
	std::cout << "vector capacity: " << vector_.capacity() << std::endl;
	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
	std::cout << "vector: " << std::endl;
	for(size_t i = 0; i < vector_.size(); i++)
		std::cout << vector_[i] << std::endl;
}

int main(void)
{
	ft::vector<int> test;
	std::cout << "test1: " << std::endl;
	testDisplay(test);
	ft::vector<int> copy(test);
	std::cout << "copy: " << std::endl;
	testDisplay(copy);
	ft::vector<int> otherVector;
	std::cout << "otherVector: " << std::endl;
	testDisplay(otherVector);
	test.push_back(999);
	std::cout << "test2: " << std::endl;
	testDisplay(test);
	otherVector = test;
	std::cout << "otherVector: " << std::endl;
	testDisplay(otherVector);
	test.push_back(7);
	std::cout << "test3: " << std::endl;
	testDisplay(test);
	test.push_back(15);
	std::cout << "test4: " << std::endl;
	testDisplay(test);
	test.push_back(19);
	std::cout << "test5: " << std::endl;
	testDisplay(test);
	test.push_back(21);
	std::cout << "test6: " << std::endl;
	testDisplay(test);
	test.push_back(23);
	std::cout << "test7: " << std::endl;
	testDisplay(test);
}
