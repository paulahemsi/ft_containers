/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:01:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/26 17:07:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename Container>
static void display_vectors(Container& vector1, Container& vector2)
{
	print_instructions("\nvector1:");
	displayVector(vector1);
	print_instructions("\nvector2:");
	displayVector(vector2);
}

template <typename Iterator>
static void display_iterators_content(Iterator& iter1, Iterator& iter2)
{
	print_instructions("*iter1:");
	std::cout << *iter1 << std::endl;
	print_instructions("*iter2:");
	std::cout << *iter2 << std::endl;
}

template <typename Container>
static void swap_vectors(Container& vector1, Container& vector2)
{
	typename Container::iterator iter1 = vector1.begin() + 3;
	typename Container::iterator iter2 = vector2.end() - 3;

	display_iterators_content(iter1, iter2);

	print_instructions("swap(vector1, vector2);");
	swap(vector1, vector2);
	display_vectors(vector1, vector2);

	display_iterators_content(iter1, iter2);
}

template <typename T>
static void fill_vectors(T content1, T content2, ft::vector<T>& vector1, ft::vector<T>& vector2)
{
	for(int i = 0; i < 8; i++)
	{
		vector1.push_back(content1);
		vector2.push_back(content2);
	}
	vector2.push_back((content2));
	display_vectors(vector1, vector2);
}

static void swap_int(void)
{
	print_subheading("int");
	ft::vector<int> vector1;
	ft::vector<int> vector2;
	
	fill_vectors<int>(1, 22, vector1, vector2);
	swap_vectors(vector1, vector2);
}

static void swap_string(void)
{
	print_subheading("string");
	ft::vector<std::string> vector1;
	ft::vector<std::string> vector2;

	fill_vectors<std::string>("one", "two", vector1, vector2);
	swap_vectors(vector1, vector2);
}

void test_swap(void)
{
	print_title("SWAP");
	swap_int();
	swap_string();
}
