/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/27 21:53:15 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include <vector>

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define RESET			"\e[0m"

template <typename T>
static void displayVector(const ft::vector<T>& vector_)
{
	std::cout << "vector capacity: " << vector_.capacity() << " vector max size: " << vector_.max_size() << std::endl;
	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
	std::cout << YELLOW << "vector: " << std::endl;
	for (typename ft::vector<T>::const_iterator element = vector_.begin(); element != vector_.end(); ++element )
		std::cout << *element << ' ';
	std::cout << std::endl << RESET << std::endl;
}

static void print_instructions(std::string instruction)
{
	std::cout << L_GRAY << instruction << RESET << std::endl;
}

static void print_title(std::string title)
{
	std::cout << CYAN << "\n\n*****" << title << "*****\n" RESET << std::endl;
}

static void test_constructors(void)
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

static void test_empty(void)
{
	print_title(".EMPTY");

	print_instructions("ft::vector<int> my_vector;");
	ft::vector<int> my_vector;
	displayVector(my_vector);

	print_instructions("my_vector.empty(): ");
	std::cout << my_vector.empty() << std::endl;
	print_instructions("my_vector.push_back(137);");
	my_vector.push_back(137);
	print_instructions("my_vector.empty(): ");
	std::cout << my_vector.empty() << std::endl;
	print_instructions("my_vector.pop_back();");
	my_vector.pop_back();
	print_instructions("my_vector.empty(): ");
	std::cout << my_vector.empty() << std::endl;

	print_instructions("ft::vector<int> four_elements(4);");
	ft::vector<int> four_elements(4);
	displayVector(four_elements);
	print_instructions("four_elements.empty(): ");
	std::cout << four_elements.empty() << std::endl;
}

static ft::vector<int> test_push_back(void)
{
	print_title(".PUSH_BACK");

	print_instructions("ft::vector<int> integers;");
	ft::vector<int> integers;
	displayVector(integers);
	print_instructions("integers.push_back(number) x 8");
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	displayVector(integers);
	return integers;
}

// static void test_insert(void)
// {
// 	print_title(".INSERT");

// 	print_instructions("ft::vector<int> integers;");
// 	ft::vector<int> integers;
// 	displayVector(integers);
// 	print_instructions("integers.insert(integers.begin(), 7);");
// 	integers.insert(integers.begin(), 7);
// 	displayVector(integers);

// 	print_instructions("integers.insert(integers.begin() + 1, 77);");
// 	integers.insert(integers.begin() + 1, 77);
// 	displayVector(integers);
// 	print_instructions("integers.insert(integers.begin() + 1, 3, 777);");
// 	integers.insert(integers.begin() + 1, 3, 777);
// 	displayVector(integers);
// }

static void test_out_of_bounds(void)
{
	print_title("OUT_OF_BOUNDS");

	print_instructions("ft::vector<int> integers(10);");
	ft::vector<int> integers(10);
	try
	{
		std::cout << "out of bounds - at(100): " << integers.at(100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "out of bounds - at(-1): " << integers.at(-1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "out of bounds [100]: " << integers[100] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "out of bounds [-1]: " << integers[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void test_pop_back(ft::vector<int> integers)
{
	print_title(".POP_BACK");
	print_instructions("integers.pop_back();");
	integers.pop_back();
	displayVector(integers);
	print_instructions("integers.pop_back();");
	integers.pop_back();
	displayVector(integers);
}

// static void test_resize(void)
// {
// 	print_title(".RESIZE");
// 	ft::vector<float> my_vector(5, 5.1);
// 	std::cout << "my_vector: " << std::endl;
// 	displayVector(my_vector);
// 	print_instructions("my_vector.resize(2);");
// 	my_vector.resize(2);
// 	std::cout << "my_vector: " << std::endl;
// 	displayVector(my_vector);
// 	std::cout << L_GRAY << "my_vector.resize(15);" << RESET << std::endl;
// 	my_vector.resize(15);
// 	displayVector(my_vector);
// }

static void test_equal_operator(void)
{
	print_title("  =  ");
	print_instructions("ft::vector<std::string> string_vector2(2, nothing);");
	ft::vector<std::string> string_vector2(2, "nothing");
	displayVector(string_vector2);
	ft::vector<std::string> string_vector;
	print_instructions("string_vector.push_back(name) x 5");
	string_vector.push_back ("Ada");
	string_vector.push_back ("Bell");
	string_vector.push_back ("Djamila");
	string_vector.push_back ("Chimamanda");
	string_vector.push_back ("Elza");
	displayVector(string_vector);
	std::cout << L_GRAY << "string_vector2 = string_vector;" << RESET << std::endl;
	string_vector2 = string_vector;
	std::cout << "string_vector2: " << std::endl;
	displayVector(string_vector2);
}

static void test_assign(void)
{
	print_title(".ASSIGN");
	print_instructions("ft::vector<int> integers;");
	ft::vector<int> integers;
	displayVector(integers);
	std::cout << L_GRAY << "integers.assign(2, 22);" << RESET << std::endl;
	integers.assign(2, 22);
	displayVector(integers);
	print_instructions("integers.push_back(number) x 3");
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	displayVector(integers);
	std::cout << L_GRAY << "integers.assign(3, 33);" << RESET << std::endl;
	integers.assign(3, 33);
	displayVector(integers);
	print_instructions("integers.push_back(number) x 8");
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	displayVector(integers);
	std::cout << L_GRAY << "integers.assign(4, 44);" << RESET << std::endl;
	integers.assign(4, 44);
	displayVector(integers);
}

static void test_at_front_back_and_dereference(void)
{
	print_title(".AT .FRONT .BACK and [] ");

	ft::vector<int> integers;
	displayVector(integers);
	print_instructions("integers.push_back(number) x 8");
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	displayVector(integers);
	std::cout << L_GRAY << "integers.at(0) = 3;" << RESET << std::endl;
	integers.at(0) = 3;
	displayVector(integers);
	std::cout << L_GRAY << "integers.at(3): " << RESET << integers.at(3) << std::endl;
	std::cout << L_GRAY << "integers[1]: " << RESET << integers[1] << std::endl;
	std::cout << L_GRAY << "integers.front(): " << RESET << integers.front() << std::endl;
	std::cout << L_GRAY << "integers.back(): " << RESET << integers.back() << std::endl;
}

static void test_iterators(void)
{
	print_title("ITERATORS");

	ft::vector<int> floats;
	print_instructions("floats.push_back(number) x 8");
	floats.push_back (59.57);
	floats.push_back (9.57);
	floats.push_back (989.57);
	floats.push_back (1009.57);
	floats.push_back (59.57);
	floats.push_back (9.57);
	floats.push_back (989.57);
	floats.push_back (1009.57);
	displayVector(floats);
	ft::vector<int> integers;
	print_instructions("integers.push_back(number) x 8");
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
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

int main(void)
{
	test_constructors();
	test_empty();
	//test_insert();
	test_out_of_bounds();
	test_pop_back(test_push_back());
	// test_resize();
	test_equal_operator();
	test_assign();
	test_at_front_back_and_dereference();
	test_iterators();
	// //integers.get_allocator();
	
	// std::vector<int>::reverse_iterator iteratorIntegers3 = integers.rbegin();
	// std::vector<int>::reverse_iterator iteratorCopyVector2 = copyVector.rbegin();
}


// static void testDisplay(ft::vector<int>& vector_)
// {
// 	std::cout << "vector capacity: " << vector_.capacity() << " vector max size: " << vector_.max_size() << std::endl;
// 	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
// 	std::cout << YELLOW << "vector: " << std::endl;
// 	for(size_t i = 0; i < vector_.size(); i++)
// 		std::cout << vector_[i] << ' ';
// 	std::cout << RESET << std::endl;
// }

// int main(void)
// {
// 	ft::vector<int> test;
// 	std::cout << "test1: " << std::endl;
// 	testDisplay(test);
// 	//std::cout << L_GRAY << "test.front(): " << RESET << test.front() << std::endl; //segfault no original
// 	//std::cout << L_GRAY << "test.back(): " << RESET << test.back() << std::endl; //segfault no original
	
// 	std::cout << CYAN << "\n\n*****empty\n" << RESET << std::endl;
// 	std::cout << L_GRAY << "test.empty(): " << RESET << test.empty() << std::endl;
// 	std::cout << L_GRAY << "test.push_back(137);" << RESET << std::endl;
// 	test.push_back(137);
// 	std::cout << L_GRAY << "test.empty(): " << RESET << test.empty() << std::endl;
// 	std::cout << L_GRAY << "test.pop_back();" << RESET << std::endl;
// 	test.pop_back();
// 	std::cout << L_GRAY << "test.empty(): " << RESET << test.empty() << std::endl;
	
// 	ft::vector<int> copy(test);
// 	std::cout << "copy: " << std::endl;
// 	testDisplay(copy);
// 	ft::vector<int> otherVector;
// 	std::cout << "otherVector: " << std::endl;
// 	testDisplay(otherVector);
// 	test.push_back(999);
// 	std::cout << "test2: " << std::endl;
// 	testDisplay(test);
// 	otherVector = test;
// 	std::cout << "otherVector: " << std::endl;
// 	testDisplay(otherVector);
// 	test.push_back(7);
// 	std::cout << "test3: " << std::endl;
// 	testDisplay(test);
// 	test.push_back(15);
// 	std::cout << "test4: " << std::endl;
// 	testDisplay(test);
// 	test.push_back(19);
// 	std::cout << "test5: " << std::endl;
// 	testDisplay(test);
// 	test.push_back(21);
// 	std::cout << "test6: " << std::endl;
// 	testDisplay(test);
// 	test.push_back(23);
// 	std::cout << "test7: " << std::endl;
// 	testDisplay(test);
// 	std::cout << CYAN << "\n\n*****trying to access out of bounds:\n" << RESET << std::endl;
// 	try
// 	{
// 		std::cout << "out of bounds - at(100): " << test.at(100) << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		std::cout << "out of bounds - at(-1): " << test.at(-1) << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		std::cout << "out of bounds [100]: " << test[100] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		std::cout << "out of bounds [-1]: " << test[-1] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << L_GRAY << "test.push_back(137);" << RESET << std::endl;
// 	test.push_back(137);
// 	std::cout << L_GRAY << "test.at(0) = 3;" << RESET << std::endl;
// 	test.at(0) = 3;
// 	testDisplay(test);
// 	std::cout << L_GRAY << "test.at(3): " << RESET << test.at(3) << std::endl;
// 	std::cout << L_GRAY << "test[1]: " << RESET << test[1] << std::endl;
// 	std::cout << L_GRAY << "test.front(): " << RESET << test.front() << std::endl;
// 	std::cout << L_GRAY << "test.back(): " << RESET << test.back() << std::endl;
// 	std::cout << L_GRAY << "test.pop_back();" << RESET << std::endl;
// 	test.pop_back();
// 	testDisplay(test);
// 	std::cout << CYAN << "\n\n*****assign:\n" << RESET << std::endl;
// 	std::cout << L_GRAY << "test.assign(2, 22);" << RESET << std::endl;
// 	test.assign(2, 22);
// 	testDisplay(test);
	
// 	std::cout << CYAN << "\n\n*****iterators:\n" << RESET << std::endl;
	
// 	ft::vector<int> copy2(test);
// 	std::cout << "copy2: " << std::endl;
// 	testDisplay(copy2);
// 	std::cout << L_GRAY << "copy2[0] = 0;" << RESET << std::endl;
// 	copy2[0] = 0;
// 	std::cout << "copy2: " << std::endl;
// 	testDisplay(copy2);

// 	ft::vector<int>::iterator iteratortest1 = test.begin();
// 	ft::vector<int>::iterator iteratortest2 = test.begin();
// 	ft::vector<int>::iterator iteratorcopy2 = copy2.begin();

// 	std::cout << L_GRAY << "(iteratortest1 == iteratortest2): " << RESET << (iteratortest1 == iteratortest2) << std::endl;
// 	std::cout << L_GRAY << "(iteratortest1 == iteratorcopy2): " << RESET << (iteratortest1 == iteratorcopy2) << std::endl;
// 	std::cout << L_GRAY << "(iteratortest1 < iteratorcopy2): " << RESET << (iteratortest1 < iteratorcopy2) << std::endl;
	
// 	std::cout << L_GRAY << "*iteratortest1: " << RESET << *iteratortest1 << std::endl;
// 	std::cout << L_GRAY << "*iteratorcopy2: " << RESET << *iteratorcopy2 << std::endl;
// 	std::cout << L_GRAY << "iteratortest1: " << RESET << &iteratortest1 << std::endl;
// 	std::cout << L_GRAY << "iteratorcopy2: " << RESET << &iteratorcopy2 << std::endl;
	
// 	std::cout << L_GRAY << "copy2[0] = test[0];" << RESET << std::endl;
// 	copy2[0] = test[0];
// 	testDisplay(copy2);
// 	testDisplay(test);
// 	iteratorcopy2 = copy2.begin();

// 	std::cout << L_GRAY << "*iteratortest1: " << RESET << *iteratortest1 << std::endl;
// 	std::cout << L_GRAY << "*iteratorcopy2: " << RESET << *iteratorcopy2 << std::endl;
// 	std::cout << L_GRAY << "iteratortest1: " << RESET << &iteratortest1 << std::endl;
// 	std::cout << L_GRAY << "iteratorcopy2: " << RESET << &iteratorcopy2 << std::endl;
	

// 	std::cout << L_GRAY << "(iteratortest1 == iteratorcopy2): " << RESET << (iteratortest1 == iteratorcopy2) << std::endl;
// 	std::cout << L_GRAY << "(iteratortest1 < iteratorcopy2): " << RESET << (iteratortest1 < iteratorcopy2) << std::endl;
// }
