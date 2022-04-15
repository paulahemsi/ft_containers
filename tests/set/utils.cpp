/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:55 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 16:17:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <cstdlib>

static int random_number(void)
{
    return rand()%1000;
}

ft::set<int>	create_set_of_random_integers(int size, int seed)
{
    ft::set<int>    set;

    srand(seed);
	
    for (int i = 0; i < size; i++)
    {
        int random = random_number();
        std::cout << L_GRAY << "include " << random << " to set" << RESET << std::endl;
	    set.insert(random);
    }
    return set;
}

ft::set<float>	create_set_of_floats(int size)
{
    ft::set<float>    set;

    size++;
    for (float i = 1; i < size; i++)
    {
        float float_to_insert = i/10 * i;
        std::cout << L_GRAY << "include " << float_to_insert << " to set" << RESET << std::endl;
        set.insert(float_to_insert);
    }
    return set;
}
