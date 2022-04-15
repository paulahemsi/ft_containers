/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:54:09 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/14 22:44:56 by lfrasson         ###   ########.fr       */
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

#endif
