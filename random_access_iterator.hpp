/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/06 18:05:42 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR
#define RANDOM_ACCESS_ITERATOR

#include "iterators_traits.hpp"

namespace ft {
	
	template <typename T>
	class random_access_iterator
	{
	private:
		pointer	_pointer;
		
	public:
		random_access_iterator(): _pointer(NULL) {};
		explicit random_access_iterator(pointer ptr): _pointer(ptr) {}
		~random_access_iterator();
	};
	
}

#endif
