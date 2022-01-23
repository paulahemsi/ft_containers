/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:27:04 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/13 20:46:12 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"

//documentation can be found in https://en.cppreference.com/w/cpp/iterator/reverse_iterator

namespace ft {

	template<class Iter>
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
		template< class U >
		reverse_iterator(const reverse_iterator<U>& other) {*this = other};
		~reverse_iterator(void) {};
	};
	
// 	Member functions
// (constructor)
 
// constructs a new iterator adaptor
// (public member function)
// operator=
 
// assigns another iterator adaptor
// (public member function)
// base
 
// accesses the underlying iterator
// (public member function)
// operator*
// operator->
 
// accesses the pointed-to element
// (public member function)
// operator[]
 
// accesses an element by index
// (public member function)
// operator++
// operator++(int)
// operator+=
// operator+
// operator--
// operator--(int)
// operator-=
// operator-
 
// advances or decrements the iterator
// (public member function)
// Member objects
// Member name	Definition
// current (protected)	the underlying iterator of which base() returns a copy
// Non-member functions
// operator==
// operator!=
// operator<
// operator<=
// operator>
// operator>=
// operator<=>
  
// (C++20)
 
// compares the underlying iterators
// (function template)
// operator+
 
// advances the iterator
// (function template)
// operator-
 
// computes the distance between two iterator adaptors
// (function template)
// iter_move
  
// (C++20)
 
// casts the result of dereferencing the adjusted underlying iterator to its associated rvalue reference type
// (function)
// iter_swap
  
// (C++20)
 
// swaps the objects pointed to by two adjusted underlying iterators
// (function template)
// make_reverse_iterator
  
// (C++14)
 
// creates a std::reverse_iterator of type inferred from the argument
// (function template)
}

#endif
