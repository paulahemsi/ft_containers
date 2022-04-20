/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:27:04 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/28 17:41:02 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterators_traits.hpp"

//documentation can be found in https://en.cppreference.com/w/cpp/iterator/reverse_iterator

namespace ft {

	template<class Iterator>
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
		//canonical
		reverse_iterator(void): _current() {};
		
		explicit reverse_iterator(iterator_type it): _current(it) {};
		
		reverse_iterator(const reverse_iterator<Iterator> &other) {*this = other;};
		
		~reverse_iterator(void) {};

		reverse_iterator& operator=(reverse_iterator const &right_hand_side)
		{
			this->_current = right_hand_side.base();
			return *this;
		}

		iterator_type base(void) const
		{
			return (this->_current);
		}

		//dereference operator
		reference	operator[](difference_type n) const
		{
			return (this->base()[n - 1]);
		}

		reference	operator*(void) const
		{
			iterator_type temp = this->_current;
			return *(temp);
		}

		pointer		operator->(void) const
		{
			return &(operator*());
		}

		//advances or decrements the iterator
		reverse_iterator& operator++(void)
		{
			this->_current--;
			return (*this);
		}
		reverse_iterator& operator--(void)
		{
			this->_current++;
			return (*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			this->_current--;
			return (temp);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			this->_current++;
			return (temp);
		}
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(base() - n); }
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(base() + n); }
		reverse_iterator& operator+=(difference_type n)
		{
			this->_current -= n;
			return (*this);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			this->_current += n;
			return (*this);
		}
	};
	
	//Non-member functions
	
	//compares the underlying iterators
	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	//advances the iterator
	template<class Iterator>
	reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return (it.base() - n);
	}

	//computes the distance between two iterator adaptors
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif
