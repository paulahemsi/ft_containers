/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:06:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/12/10 20:35:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define RESET			"\e[0m"


template <typename T>
void displayVector(const std::vector<T>& vector_)
{
	std::cout << "vector capacity: " << vector_.capacity() << "vector max size: " << vector_.max_size() << std::endl;
	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
	std::cout << YELLOW << "\nvector: " << std::endl;
	for (typename std::vector<T>::const_iterator element = vector_.begin(); element != vector_.end(); ++element )
		std::cout << *element << ' ';
	std::cout << RESET << std::endl;
}

int main (void)
{
	std::cout << CYAN << "\n\n*****basic constructor\n" << RESET << std::endl;

	std::cout << L_GRAY << "std::vector<int> integers;" << RESET << std::endl;
	std::vector<int> integers;
	displayVector(integers);

	std::cout << CYAN << "\n\n*****passing a size to constructor\n" << RESET << std::endl;
	std::cout << L_GRAY << "std::vector<int> tenElements (10);" << RESET << std::endl;
	std::vector<int> tenElements(10);
	displayVector(tenElements);

	std::cout << CYAN << "\n\n*****passing a size and a standart value to constructor\n" << RESET << std::endl;
	std::cout << L_GRAY << "std::vector<int> tenElement90 (10, 90);" << RESET << std::endl;
	std::vector<int> tenElement90(10, 90);
	displayVector(tenElement90);

	std::cout << CYAN << "\n\n*****copy constructor\n" << RESET << std::endl;
	std::cout << L_GRAY << "std::vector<int> copyVector (tenElement90);" << RESET << std::endl;
	std::vector<int> copyVector(tenElement90);
	displayVector(copyVector);

	std::cout << CYAN << "\n\n*****partial copy with iterators (constructor with iterators)\n" << RESET << std::endl;
	std::cout << L_GRAY << "std::vector<int> partialCopy (tenElements.begin(), tenElements.begin() + 5);" << RESET << std::endl;
	std::vector<int> partialCopy(tenElements.begin(),
	tenElements.begin() + 5);
	displayVector(partialCopy);

	std::cout << CYAN << "\n\n*****adding new elements to integers vector\n" << RESET << std::endl;
	std::cout << "The integers vector contains ";
	std::cout << integers.size() << " Elements" << std::endl;
	std::cout << L_GRAY << "integers.push_back(number) x 4" << RESET << std::endl;
	integers.push_back (50);
	integers.push_back (1);
	integers.push_back (987);
	integers.push_back (1001);
	displayVector(integers);

	std::cout << CYAN << "\n\n*****adding new element in the begining with insert\n" << RESET << std::endl;
	std::cout << L_GRAY << "integers.insert(integers.begin(), 7);" << RESET << std::endl;
	integers.insert(integers.begin(), 7);
	displayVector(integers);

	std::cout << CYAN << "\n\n*****adding new element in the begining + 3 with insert\n" << RESET << std::endl;
	std::cout << L_GRAY << "integers.insert(integers.begin() + 3, 77);\nintegers.insert(integers.begin() + 3, 3, 777);" << RESET << std::endl;
	integers.insert(integers.begin() + 3, 77);
	integers.insert(integers.begin() + 3, 3, 777);
	displayVector(integers);

	std::cout << CYAN << "\n\n*****accessing specific index (0) with .at(index):\n" << RESET << std::endl;
	std::cout << "at(0): " << integers.at(0) << std::endl;

	std::cout << CYAN << "\n\n*****trying to access out od bounds:\n" << RESET << std::endl;
	try
	{
		std::cout << "out of bounds - at(100): " << integers.at(100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << CYAN << "\n\n*****poping out last value:\n" << RESET << std::endl;
	std::cout << L_GRAY << "integers.pop_back();" << RESET << std::endl;
	integers.pop_back();
	displayVector(integers);
}
