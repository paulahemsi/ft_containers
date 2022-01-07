/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/07 19:30:20 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include <vector>

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define RESET			"\e[0m"

static void testDisplay(ft::vector<int>& vector_)
{
	std::cout << "vector capacity: " << vector_.capacity() << " vector max size: " << vector_.max_size() << std::endl;
	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
	std::cout << YELLOW << "vector: " << std::endl;
	for(size_t i = 0; i < vector_.size(); i++)
		std::cout << vector_[i] << ' ';
	std::cout << RESET << std::endl;
}

int main(void)
{
	ft::vector<int> test;
	std::cout << "test1: " << std::endl;
	testDisplay(test);
	//std::cout << L_GRAY << "test.front(): " << RESET << test.front() << std::endl; //segfault no original
	//std::cout << L_GRAY << "test.back(): " << RESET << test.back() << std::endl; //segfault no original
	
	std::cout << CYAN << "\n\n*****empty\n" << RESET << std::endl;
	std::cout << L_GRAY << "test.empty(): " << RESET << test.empty() << std::endl;
	std::cout << L_GRAY << "test.push_back(137);" << RESET << std::endl;
	test.push_back(137);
	std::cout << L_GRAY << "test.empty(): " << RESET << test.empty() << std::endl;
	std::cout << L_GRAY << "test.pop_back();" << RESET << std::endl;
	test.pop_back();
	std::cout << L_GRAY << "test.empty(): " << RESET << test.empty() << std::endl;
	
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
	std::cout << CYAN << "\n\n*****trying to access out of bounds:\n" << RESET << std::endl;
	try
	{
		std::cout << "out of bounds - at(100): " << test.at(100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "out of bounds - at(-1): " << test.at(-1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "out of bounds [100]: " << test[100] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "out of bounds [-1]: " << test[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << L_GRAY << "test.push_back(137);" << RESET << std::endl;
	test.push_back(137);
	std::cout << L_GRAY << "test.at(0) = 3;" << RESET << std::endl;
	test.at(0) = 3;
	testDisplay(test);
	std::cout << L_GRAY << "test.at(3): " << RESET << test.at(3) << std::endl;
	std::cout << L_GRAY << "test[1]: " << RESET << test[1] << std::endl;
	std::cout << L_GRAY << "test.front(): " << RESET << test.front() << std::endl;
	std::cout << L_GRAY << "test.back(): " << RESET << test.back() << std::endl;
	std::cout << L_GRAY << "test.pop_back();" << RESET << std::endl;
	test.pop_back();
	testDisplay(test);
	std::cout << CYAN << "\n\n*****assign:\n" << RESET << std::endl;
	std::cout << L_GRAY << "test.assign(2, 22);" << RESET << std::endl;
	test.assign(2, 22);
	testDisplay(test);
	
	std::cout << CYAN << "\n\n*****iterators:\n" << RESET << std::endl;
	
	ft::vector<int> copy2(test);
	std::cout << "copy2: " << std::endl;
	testDisplay(copy2);
	std::cout << L_GRAY << "copy2[0] = 0;" << RESET << std::endl;
	copy2[0] = 0;
	std::cout << "copy2: " << std::endl;
	testDisplay(copy2);

	ft::vector<int>::iterator iteratortest1 = test.begin();
	ft::vector<int>::iterator iteratortest2 = test.begin();
	ft::vector<int>::iterator iteratorcopy2 = copy2.begin();

	std::cout << L_GRAY << "(iteratortest1 == iteratortest2): " << RESET << (iteratortest1 == iteratortest2) << std::endl;
	std::cout << L_GRAY << "(iteratortest1 == iteratorcopy2): " << RESET << (iteratortest1 == iteratorcopy2) << std::endl;
	std::cout << L_GRAY << "(iteratortest1 < iteratorcopy2): " << RESET << (iteratortest1 < iteratorcopy2) << std::endl;
	
	std::cout << L_GRAY << "*iteratortest1: " << RESET << *iteratortest1 << std::endl;
	std::cout << L_GRAY << "*iteratorcopy2: " << RESET << *iteratorcopy2 << std::endl;
	std::cout << L_GRAY << "iteratortest1: " << RESET << &iteratortest1 << std::endl;
	std::cout << L_GRAY << "iteratorcopy2: " << RESET << &iteratorcopy2 << std::endl;
	
	std::cout << L_GRAY << "copy2[0] = test[0];" << RESET << std::endl;
	copy2[0] = test[0];
	testDisplay(copy2);
	testDisplay(test);
	iteratorcopy2 = copy2.begin();

	std::cout << L_GRAY << "*iteratortest1: " << RESET << *iteratortest1 << std::endl;
	std::cout << L_GRAY << "*iteratorcopy2: " << RESET << *iteratorcopy2 << std::endl;
	std::cout << L_GRAY << "iteratortest1: " << RESET << &iteratortest1 << std::endl;
	std::cout << L_GRAY << "iteratorcopy2: " << RESET << &iteratorcopy2 << std::endl;
	

	std::cout << L_GRAY << "(iteratortest1 == iteratorcopy2): " << RESET << (iteratortest1 == iteratorcopy2) << std::endl;
	std::cout << L_GRAY << "(iteratortest1 < iteratorcopy2): " << RESET << (iteratortest1 < iteratorcopy2) << std::endl;
}
