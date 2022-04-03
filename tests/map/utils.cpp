/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:55 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/03 17:25:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <cstdlib>

static int random_number(void)
{
    return rand()%1000;
}

// ft::map<int, int>	create_vector_of_random_integers(int size, int seed)
// {
//     ft::map<int, int>    map(size);

//     srand(seed);
//     std::generate (map.begin(), map.end(), random_number);
//     return map;
// }

ft::map<int, int>	create_map_of_random_integers(int size, int seed)
{
    ft::map<int, int>    map;

    srand(seed);
	
    for (int i = 0; i < size; i++)
    {
        int random = random_number();
        const ft::pair<const int, int>	*pair = new ft::pair<const int, int>(random, random);
	    map.insert(*pair);
    }
    return map;
}
