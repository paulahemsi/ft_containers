/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:16:02 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/14 22:37:12 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <time.h>

int main(void)
{
	clock_t start;
	clock_t end;
	clock_t elapsed_time;

	start = clock();

	std::cout.setf(std::ios::boolalpha);

	end = clock();
	elapsed_time = end - start;
	print_title(VERSION);
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;

	return (0);
}