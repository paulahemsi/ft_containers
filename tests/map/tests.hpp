/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/04 23:30:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <vector>
#else
	#define VERSION "FT_VERSION"
	#include "Vector.hpp"
#endif

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define RESET			"\e[0m"

int test_pair(void);

#endif
