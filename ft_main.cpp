/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/12/11 19:39:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int main(void)
{
	ft::Vector<int> test;
	ft::Vector<int> copy(test);
	ft::Vector<int> otherVector;
	otherVector = test;
}
