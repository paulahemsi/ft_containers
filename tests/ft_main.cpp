/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/22 20:18:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int main(void)
{
	test_constructors();
	test_empty();
	test_pop_back(test_push_back());
	test_out_of_bounds();
	test_equal_operator();
	test_assign();
	test_at_front_back_and_dereference();
	test_iterators();
	test_const_iterators();
	test_reverse_iterators();
	test_data();
	test_clear();
	test_erase();
	test_reserve();
	test_get_allocator();
	test_resize();
	test_insert();
	test_relational_operators();
	test_swap();
}
