/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:19:03 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/06 19:56:00 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUXILIARY_HPP
# define AUXILIARY_HPP

# include <iostream>

# define CYAN			"\e[0;36m"
# define L_GRAY			"\e[0;38;5;245m"
# define YELLOW			"\e[0;33m"
# define ORANGE			"\e[0;38;5;166m"
# define RESET			"\e[0m"

void print_instructions(std::string instruction);
void print_title(std::string title);
void print_subheading(std::string subheading);

#endif