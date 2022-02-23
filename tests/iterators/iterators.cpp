/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:40:06 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/23 14:42:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static int random_number(void)
{
    return std::rand()%1000;
}

static ft::vector<int>	create_vector(int size, int seed)
{
    ft::vector<int>    vector(size);
    
    std::srand(seed);
    std::generate (vector.begin(), vector.end(), random_number);
    return vector;
}

static void	compare_iterator_of_same_vector(ft::vector<int> vector)
{
	ft::vector<int>::iterator iterator1 = vector.begin();
	ft::vector<int>::iterator iterator2 = vector.begin();

	std::cout << L_GRAY
				<< "(iterator1 == iterator2): "
				<< RESET
				<< (iterator1 == iterator2)
				<< std::endl;
}

static void compare_iterator_of_two_vectors(ft::vector<int> vector1, ft::vector<int> vector2)
{
	ft::vector<int>::iterator iterator1 = vector1.begin();
	ft::vector<int>::iterator iterator2 = vector2.begin();
	
	std::cout << L_GRAY << "(iterator1 == iterator2): " << RESET << (iterator1 == iterator2) << std::endl;
	std::cout << L_GRAY << "(iterator1 < iterator2): " << RESET << (iterator1 < iterator2) << std::endl;
	std::cout << L_GRAY << "*iterator1: " << RESET << *iterator1 << std::endl;
	std::cout << L_GRAY << "*iterator2: " << RESET << *iterator2 << std::endl;
	std::cout << L_GRAY << "iterator1: " << RESET << &iterator1 << std::endl;
	std::cout << L_GRAY << "iterator2: " << RESET << &iterator2 << std::endl;

}

void test_iterators(void)
{
	print_title("ITERATORS");

	print_instructions("vector1.push_back(number) x 8");
	ft::vector<int> vector1 = create_vector(8, 200);
	displayVector(vector1);
	compare_iterator_of_same_vector(vector1);
	
	print_instructions("\nvector2.push_back(number) x 8");
	ft::vector<int> vector2 = create_vector(8, 1000);
	displayVector(vector2);
	compare_iterator_of_two_vectors(vector1, vector2);

	std::cout << L_GRAY << "vector2[0] = vector1[0];" << RESET << std::endl;	
	vector2[0] = vector1[0];

	compare_iterator_of_two_vectors(vector1, vector2);
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