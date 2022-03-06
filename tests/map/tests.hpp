/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/05 20:31:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <iostream>

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <utility>
#else
	#define VERSION "FT_VERSION"
	#include "pair.tpp"
#endif

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define RESET			"\e[0m"

void test_pair(void);

/*
* Auxiliary
*/
void print_instructions(std::string instruction);
void print_title(std::string title);
void print_subheading(std::string subheading);

#endif
