/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/02/22 13:54:27 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <iostream>
# include <vector>
# include "Vector.hpp"

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define RESET			"\e[0m"

template <typename T>
void displayVector(const ft::vector<T>& vector_)
{
	std::cout << "vector capacity: " << vector_.capacity() << " vector max size: " << vector_.max_size() << std::endl;
	std::cout << "The vector contains " << vector_.size () << " elements" << std::endl;
	std::cout << YELLOW << "vector: " << std::endl;
	for (typename ft::vector<T>::const_iterator element = vector_.begin(); element != vector_.end(); ++element )
		std::cout << *element << ' ';
	std::cout << std::endl << RESET << std::endl;
}

void print_instructions(std::string instruction);
void print_title(std::string title);

#endif
