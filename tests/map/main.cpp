/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:16:02 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/06 18:48:47 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void test_constructors(void)
{
	print_title("CONSTRUCTORS");
	
	ft::map<int, int>	my_map;
	const ft::pair<const int, int>	my_pair =  ft::make_pair(1, 1);


	my_map.insert(my_pair);
	my_map.begin();
	
}

static void	test_iterators(void)
{
	print_title("ITERATORS");
	
	ft::map<int, int> map = create_map_of_random_integers(8, 200);
	
	print_subheading("bidirectional");
	ft::map<int, int>::iterator it;

	for (it = map.begin(); it != map.end(); ++it) {
 	   std::cout << it->first << ", " << it->second << '\n';
	}

	print_subheading("reverse");
	ft::map<int, int>::reverse_iterator	reverse_it;
	
	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it) {
 	std::cout << reverse_it->first << ", " << reverse_it->second << '\n';
	}
}

static void print_found(ft::map<float, float>::iterator it, ft::map<float, float>::iterator end)
{
	if (it != end)
		std::cout << "Found: key " << it->first << " value " << it->second << std::endl;
	else 
		std::cout << "not found" << std::endl;
}


ft::map<float, float>	create_map_of_floats(int size)
{
    ft::map<float, float>    map;

    size++;
    for (float i = 1; i < size; i++)
    {
        float float_to_insert = i/10 * i;
        std::cout << "include " << float_to_insert << ", " << float_to_insert << " to map" << std::endl;
        const ft::pair<const float, float>	*pair = new ft::pair<const float, float>(float_to_insert, float_to_insert);
        map.insert(*pair);
    }
    return map;
}


static void test_find(void)
{
	print_title("FIND");

	ft::map<float, float> map_to_test = create_map_of_floats(7);

	ft::map<float, float>::iterator end = map_to_test.end();
	for (float i = 4; i < 9; i++)
	{
		float number_to_find = i / 10 * i;
		std::cout << "number to find: " << number_to_find << std::endl;
		ft::map<float, float>::iterator found = map_to_test.find((number_to_find));
		print_found(found, end);
	}
}

int main(void)
{
	print_title(VERSION);
	std::cout.setf(std::ios::boolalpha);
	test_pair();
	test_constructors();
	test_iterators();
	test_find();
}
