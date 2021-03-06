/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:55 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 21:37:50 by phemsi-a         ###   ########.fr       */
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
      //  std::cout << L_GRAY << "include " << random << ", " << random << " to map" << RESET << std::endl;
        const ft::pair<const int, int>	pair(random, random);
	    map.insert(pair);
    }
    return map;
}

ft::map<float, float>	create_map_of_floats(int size)
{
    ft::map<float, float>    map;

    size++;
    for (float i = 1; i < size; i++)
    {
        float float_to_insert = i/10 * i;
       // std::cout << L_GRAY << "include " << float_to_insert << ", " << float_to_insert << " to map" << RESET << std::endl;
        const ft::pair<const float, float>	pair(float_to_insert, float_to_insert);
        map.insert(pair);
    }
    return map;
}
