/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 12:15:27 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <iostream>
#include "Stack.hpp"
#include "auxiliary.hpp"

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <stack>
#else
	#define VERSION "FT_VERSION"
	#include "pair.tpp"
#endif

void test_canonical_form(void);
void test_size(void);
void test_pop(void);
void test_push(void);
void test_top(void);
void test_empty(void);

#endif
