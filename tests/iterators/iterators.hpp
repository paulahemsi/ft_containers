/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:37:45 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/02 21:50:14 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include "tests.hpp"

void	getBegin(ft::vector<int>& vector, ft::vector<int>::iterator& iterator);
void	getBegin(ft::vector<int>& vector, ft::vector<int>::const_iterator& iterator);
void	getBegin(ft::vector<int>& vector, ft::vector<int>::reverse_iterator& iterator);
void	getBegin(ft::vector<int>& vector, ft::vector<int>::const_reverse_iterator& iterator);
void	getEnd(ft::vector<int>& vector, ft::vector<int>::iterator& iterator);
void	getEnd(ft::vector<int>& vector, ft::vector<int>::const_iterator& iterator);
void	getEnd(ft::vector<int>& vector, ft::vector<int>::reverse_iterator& iterator);
void	getEnd(ft::vector<int>& vector, ft::vector<int>::const_reverse_iterator& iterator);
void	change_value(ft::vector<int>& vector, int index1, int index2);

#endif