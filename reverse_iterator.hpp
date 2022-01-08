/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:27:04 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/08 14:52:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"

//documentation can be found in https://en.cppreference.com/w/cpp/iterator/reverse_iterator

namespace ft {

	template<typename T>
	class reverse_iterator
	{
	public:
		//member types until C++20 
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	protected:
		//member objects (the underlying iterator of which base() returns a copy)
		iterator_type	_current;

	public:
		//member functions
		reverse_iterator(void): _current() {};
		explicit reverse_iterator(iterator_type x): _current(x) {};
		// template< class U >
		// reverse_iterator(const reverse_iterator<U>& other);
		~reverse_iterator(void);
	};	
}

#endif
