/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/29 20:39:43 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <iostream>
#include "Map.hpp"
#include "auxiliary.hpp"

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <utility>
#else
	#define VERSION "FT_VERSION"
	#include "pair.tpp"
#endif

void test_pair(void);

#endif
