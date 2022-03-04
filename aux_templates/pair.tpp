/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:43:14 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/03/04 20:54:10 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* This class couples together a pair of values, which may be of different types (T1 and T2). 
* The individual values can be accessed through its public members first and second.
*/

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		public:

			pair(): first(T1()), second(T2()) {}

			template<class U, class V>
			pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}

			pair (const first_type& a, const second_type& b): first(a), second(b) {}
	};
}
