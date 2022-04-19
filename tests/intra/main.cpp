/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:02:07 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 23:08:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#define VERSION "FT_VERSION"
	#include <Map.hpp>
	#include <Stack.hpp>
	#include <Vector.hpp>
#endif

#include <stdlib.h>
#include "auxiliary.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	clock_t start;
	clock_t end;
	clock_t elapsed_time;

	start = clock();
	print_title(" VECTOR OF BUFFER ");
	print_instructions("Push values...");
	for (int i = 0; i < COUNT; i++)
		vector_buffer.push_back(Buffer());

	print_instructions("Access random positions to replace values...");
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}

	print_instructions("Swap content with empty vector");
	ft::vector<Buffer>().swap(vector_buffer);

	print_instructions("Try access some content");
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "OK!! Exception raised =) " <<std::endl;
	}
	
	end = clock();
	elapsed_time = end - start;
	print_title(VERSION);
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
	start = clock();

	print_title(" MAP OF (int, int) ");
	print_instructions("Insert pairs...");
	for (int i = 0; i < COUNT; ++i)
		map_int.insert(ft::make_pair(rand(), rand()));

	print_instructions("Sum of values accessed randonly...");
	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand() % COUNT;
		sum += map_int[access];
	}
	std::cout << "If run this test again, the follow value should be constant with the same seed: " << sum << std::endl;

	print_instructions("Create a copy in a scope to check deep copy");

	{
		ft::map<int, int> copy = map_int;
	}

	print_instructions("Access some value of map");
	sum += map_int[10];

	print_title(" STACK ");
	MutantStack<char> iterable_stack;
	print_instructions("Push latter from \'a\' to \'z\'...");
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);

	print_instructions("Iterate with mutant stack to print values:");
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		std::cout << *it;
	std::cout << std::endl;

	end = clock();
	elapsed_time = end - start;
	print_title(VERSION);
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;

	return (0);
}
