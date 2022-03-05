/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:01:52 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/27 12:58:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "swap.tpp"

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
