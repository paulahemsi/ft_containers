/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:40:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/23 14:03:23 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static int random_number(void)
{
    return std::rand()%1000;
}

ft::vector<int>	create_vector(int size, int seed)
{
    ft::vector<int>    vector(size);
    
    std::srand(seed);
    std::generate (vector.begin(), vector.end(), random_number);
    return vector;
}

void test_iterators(void)
{
	print_title("ITERATORS");

	print_instructions("floats.push_back(number) x 8");
	ft::vector<int> floats = create_vector(8, 1000);
	displayVector(floats);
	
	print_instructions("integers.push_back(number) x 8");
	ft::vector<int> integers = create_vector(8, 200);
	displayVector(integers);
	
	ft::vector<int>::iterator iteratorIntegers1 = integers.begin();
	ft::vector<int>::iterator iteratorIntegers2 = integers.begin();
	ft::vector<int>::iterator iteratorfloats = floats.begin();
	
	std::cout << L_GRAY << "(iteratorIntegers1 == iteratorIntegers2): " << RESET << (iteratorIntegers1 == iteratorIntegers2) << std::endl;
	std::cout << L_GRAY << "(iteratorIntegers1 == iteratorfloats): " << RESET << (iteratorIntegers1 == iteratorfloats) << std::endl;
	std::cout << L_GRAY << "(iteratorIntegers1 < iteratorfloats): " << RESET << (iteratorIntegers1 < iteratorfloats) << std::endl;
	
	std::cout << L_GRAY << "*iteratorIntegers1: " << RESET << *iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "*iteratorfloats: " << RESET << *iteratorfloats << std::endl;
	std::cout << L_GRAY << "iteratorIntegers1: " << RESET << &iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "iteratorfloats: " << RESET << &iteratorfloats << std::endl;
	
	std::cout << L_GRAY << "floats[0] = integers[0];" << RESET << std::endl;	
	floats[0] = integers[0];
	iteratorfloats = floats.begin();

	std::cout << L_GRAY << "*iteratorIntegers1: " << RESET << *iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "*iteratorfloats: " << RESET << *iteratorfloats << std::endl;
	std::cout << L_GRAY << "iteratorIntegers1: " << RESET << &iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "iteratorfloats: " << RESET << &iteratorfloats << std::endl;
	

	std::cout << L_GRAY << "(iteratorIntegers1 == iteratorfloats): " << RESET << (iteratorIntegers1 == iteratorfloats) << std::endl;
	std::cout << L_GRAY << "(iteratorIntegers1 < iteratorfloats): " << RESET << (iteratorIntegers1 < iteratorfloats) << std::endl;
}

void test_const_iterators(void)
{
	print_title("CONST ITERATORS");

	print_instructions("floats.push_back(number) x 8");
	ft::vector<int> floats = create_vector(8, 1000);
	displayVector(floats);
	
	print_instructions("integers.push_back(number) x 8");
	ft::vector<int> integers = create_vector(8, 200);
	displayVector(integers);
	
	ft::vector<int>::const_iterator iteratorIntegers1 = integers.begin();
	ft::vector<int>::const_iterator iteratorIntegers2 = integers.begin();
	ft::vector<int>::const_iterator iteratorfloats = floats.begin();
	
	std::cout << L_GRAY << "(iteratorIntegers1 == iteratorIntegers2): " << RESET << (iteratorIntegers1 == iteratorIntegers2) << std::endl;
	std::cout << L_GRAY << "(iteratorIntegers1 == iteratorfloats): " << RESET << (iteratorIntegers1 == iteratorfloats) << std::endl;
	std::cout << L_GRAY << "(iteratorIntegers1 < iteratorfloats): " << RESET << (iteratorIntegers1 < iteratorfloats) << std::endl;
	
	std::cout << L_GRAY << "*iteratorIntegers1: " << RESET << *iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "*iteratorfloats: " << RESET << *iteratorfloats << std::endl;
	std::cout << L_GRAY << "iteratorIntegers1: " << RESET << &iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "iteratorfloats: " << RESET << &iteratorfloats << std::endl;
	
	std::cout << L_GRAY << "floats[0] = integers[0];" << RESET << std::endl;	
	floats[0] = integers[0];
	iteratorfloats = floats.begin();

	std::cout << L_GRAY << "*iteratorIntegers1: " << RESET << *iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "*iteratorfloats: " << RESET << *iteratorfloats << std::endl;
	std::cout << L_GRAY << "iteratorIntegers1: " << RESET << &iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "iteratorfloats: " << RESET << &iteratorfloats << std::endl;
	

	std::cout << L_GRAY << "(iteratorIntegers1 == iteratorfloats): " << RESET << (iteratorIntegers1 == iteratorfloats) << std::endl;
	std::cout << L_GRAY << "(iteratorIntegers1 < iteratorfloats): " << RESET << (iteratorIntegers1 < iteratorfloats) << std::endl;
}

void test_reverse_iterators(void)
{
	print_title("REVERSE ITERATORS");

	print_instructions("floats.push_back(number) x 8");
	ft::vector<int> floats = create_vector(8, 1000);
	displayVector(floats);
	
	print_instructions("integers.push_back(number) x 8");
	ft::vector<int> integers = create_vector(8, 200);
	displayVector(integers);
	
	ft::vector<int>::reverse_iterator reverse_iteratorIntegers1 = integers.rbegin();
	ft::vector<int>::reverse_iterator reverse_iteratorIntegers2 = integers.rbegin();
	ft::vector<int>::reverse_iterator reverse_iteratorfloats = floats.rbegin();
	
	std::cout << L_GRAY << "(reverse_iteratorIntegers1 == reverse_iteratorIntegers2): " << RESET << (reverse_iteratorIntegers1 == reverse_iteratorIntegers2) << std::endl;
	std::cout << L_GRAY << "(reverse_iteratorIntegers1 == reverse_iteratorfloats): " << RESET << (reverse_iteratorIntegers1 == reverse_iteratorfloats) << std::endl;
	std::cout << L_GRAY << "(reverse_iteratorIntegers1 < reverse_iteratorfloats): " << RESET << (reverse_iteratorIntegers1 < reverse_iteratorfloats) << std::endl;
	
	std::cout << L_GRAY << "*reverse_iteratorIntegers1: " << RESET << *reverse_iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "*reverse_iteratorfloats: " << RESET << *reverse_iteratorfloats << std::endl;
	std::cout << L_GRAY << "reverse_iteratorIntegers1: " << RESET << &reverse_iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "reverse_iteratorfloats: " << RESET << &reverse_iteratorfloats << std::endl;
	
	std::cout << L_GRAY << "floats[0] = integers[0];" << RESET << std::endl;	
	floats[0] = integers[0];
	reverse_iteratorfloats = floats.rbegin();

	std::cout << L_GRAY << "*reverse_iteratorIntegers1: " << RESET << *reverse_iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "*reverse_iteratorfloats: " << RESET << *reverse_iteratorfloats << std::endl;
	std::cout << L_GRAY << "reverse_iteratorIntegers1: " << RESET << &reverse_iteratorIntegers1 << std::endl;
	std::cout << L_GRAY << "reverse_iteratorfloats: " << RESET << &reverse_iteratorfloats << std::endl;
	

	std::cout << L_GRAY << "(reverse_iteratorIntegers1 == reverse_iteratorfloats): " << RESET << (reverse_iteratorIntegers1 == reverse_iteratorfloats) << std::endl;
	std::cout << L_GRAY << "(reverse_iteratorIntegers1 < reverse_iteratorfloats): " << RESET << (reverse_iteratorIntegers1 < reverse_iteratorfloats) << std::endl;

	ft::vector<int>::reverse_iterator rend = integers.rend();
	while (reverse_iteratorIntegers1 <= rend)
	{
		std::cout << *reverse_iteratorIntegers1 << std::endl;
		reverse_iteratorIntegers1++;
	}
}