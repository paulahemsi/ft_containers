/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:55 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/06 19:20:17 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auxiliary.hpp"

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