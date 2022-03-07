/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:57:55 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/06 22:15:38 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static int random_number(void)
{
    return rand()%1000;
}

ft::vector<int>	create_vector_of_random_integers(int size, int seed)
{
    ft::vector<int>    vector(size);

    srand(seed);
    std::generate (vector.begin(), vector.end(), random_number);
    return vector;
}
