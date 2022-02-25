/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:55 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/25 10:30:43 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void print_instructions(std::string instruction)
{
	std::cout << L_GRAY << instruction << RESET << std::endl;
}

void print_title(std::string title)
{
	std::cout << CYAN << "\n\n*******" << title << "*******\n" RESET << std::endl;
}

void print_subheading(std::string subheading)
{
	std::cout << CYAN << "\n\n---" << subheading << "---\n" RESET << std::endl;
}

static int random_number(void)
{
    return std::rand()%1000;
}

ft::vector<int>	create_vector_of_random_integers(int size, int seed)
{
    ft::vector<int>    vector(size);

    std::srand(seed);
    std::generate (vector.begin(), vector.end(), random_number);
    return vector;
}