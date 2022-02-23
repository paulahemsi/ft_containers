/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/22 20:18:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static ft::vector<int> test_push_back(void)
{
	print_title(".PUSH_BACK");

	print_instructions("ft::vector<int> integers;");
	ft::vector<int> integers;
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
	return integers;
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

static void test_at_front_back_and_dereference(void)
{
	print_title(".AT .FRONT .BACK and [] ");

	ft::vector<int> integers;
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
	std::cout << L_GRAY << "integers.at(0) = 3;" << RESET << std::endl;
	integers.at(0) = 3;
	displayVector(integers);
	std::cout << L_GRAY << "integers.at(3): " << RESET << integers.at(3) << std::endl;
	std::cout << L_GRAY << "integers[1]: " << RESET << integers[1] << std::endl;
	std::cout << L_GRAY << "integers.front(): " << RESET << integers.front() << std::endl;
	std::cout << L_GRAY << "integers.back(): " << RESET << integers.back() << std::endl;
}

static void test_reserve(void)
{
	print_title("RESERVE");

	ft::vector<int> integers;
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

	print_instructions("integers.reserve(3);");
	integers.reserve(3);
	displayVector(integers);
	print_instructions("integers.reserve(30);");
	integers.reserve(30);
	displayVector(integers);
}

static void test_get_allocator(void)
{
	print_title("GET_ALLOCATOR");

	ft::vector<int> myvector;
	int * pointer;

	// allocate an array with space for 5 elements using vector's allocator:
	pointer = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (size_t i = 0; i < 5; i++)
		myvector.get_allocator().construct(&pointer[i], i);

	std::cout << "The allocated array contains:";
	for (size_t i = 0; i < 5; i++)
		std::cout << ' ' << pointer[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (size_t i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&pointer[i]);
	myvector.get_allocator().deallocate(pointer,5);
}

static void test_resize(void)
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

static void test_swap(void)
{
	print_title("SWAP");

	ft::vector<int> vector1;
	print_instructions("vector1.push_back(number) x 8");
	vector1.push_back(0);
	vector1.push_back(1);
	vector1.push_back(2);
	vector1.push_back(3);
	vector1.push_back(4);
	vector1.push_back(5);
	vector1.push_back(6);
	vector1.push_back(7);
	displayVector(vector1);

	ft::vector<int> vector2;
	print_instructions("vector2.push_back(number) x 9");
	vector2.push_back(999999999);
	vector2.push_back(88888888);
	vector2.push_back(7777777);
	vector2.push_back(666666);
	vector2.push_back(55555);
	vector2.push_back(4444);
	vector2.push_back(333);
	vector2.push_back(22);
	vector2.push_back(1);
	displayVector(vector2);

	ft::vector<int>::iterator iter_3 = vector1.begin() + 3;
	ft::vector<int>::iterator iter_333 = vector2.end() - 3;

	print_instructions("std::cout << *iter_3 << std::endl;");
	std::cout << *iter_3 << std::endl;
	print_instructions("std::cout << *iter_333 << std::endl;");
	std::cout << *iter_333 << std::endl;

	print_instructions("swap(vector1, vector2);");
	swap(vector1, vector2);
	print_instructions("\ndisplayVector(vector1);");
	displayVector(vector1);
	print_instructions("displayVector(vector2);");
	displayVector(vector2);

	print_instructions("std::cout << *iter_3 << std::endl;");
	std::cout << *iter_3 << std::endl;
	print_instructions("std::cout << *iter_333 << std::endl;");
	std::cout << *iter_333 << std::endl;
}

int main(void)
{
	test_constructors();
	test_empty();
	test_pop_back(test_push_back());
	test_out_of_bounds();
	test_equal_operator();
	test_assign();
	test_at_front_back_and_dereference();
	test_iterators();
	test_const_iterators();
	test_reverse_iterators();
	test_data();
	test_clear();
	test_erase();
	test_reserve();
	test_get_allocator();
	test_resize();
	test_insert();
	test_relational_operators();
	test_swap();
}
