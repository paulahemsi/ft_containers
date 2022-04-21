/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/21 19:50:57 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft {

	template <typename T>
	class random_access_iterator
	{
		public:
			typedef	random_access_iterator<T>		iterator;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::ptrdiff_t					difference_type;
			typedef random_access_iterator<const T>	const_iterator;

		private:
			pointer	_pointer;

		public:
			//canonical
			random_access_iterator(): _pointer(NULL) {}

			explicit random_access_iterator(pointer ptr): _pointer(ptr) {}

			random_access_iterator(const random_access_iterator& instance) {*this = instance;}

			~random_access_iterator() {}

			random_access_iterator& operator=(const random_access_iterator& right_hand_side)
			{
				this->_pointer = right_hand_side._pointer;
				return *this;
			}

			pointer base(void) const
			{
				return (this->_pointer);
			}

			// convertion to const if needed
			operator const_iterator() const {return const_iterator(_pointer);}

			//relational operators overload
			bool operator==(const iterator& right_hand_side)
			{
				return this->_pointer == right_hand_side._pointer;
			}
			bool operator!=(const iterator& right_hand_side)
			{
				return this->_pointer != right_hand_side._pointer;
			}
			bool operator>(const iterator& right_hand_side)
			{
				return this->_pointer > right_hand_side._pointer;
			}
			bool operator>=(const iterator& right_hand_side)
			{
				return this->_pointer >= right_hand_side._pointer;
			}
			bool operator<(const iterator& right_hand_side)
			{
				return this->_pointer < right_hand_side._pointer;
			}
			bool operator<=(const iterator& right_hand_side)
			{
				return this->_pointer <= right_hand_side._pointer;
			}

			//increment and decrement
			iterator& operator++(void)
			{
				this->_pointer++;
				return (*this);
			}
			iterator& operator--(void)
			{
				this->_pointer--;
				return (*this);
			}
			iterator operator++(int)
			{
				iterator copy(*this);
				this->_pointer++;
				return (copy);
			}
			iterator operator--(int)
			{
				iterator copy(*this);
				this->_pointer--;
				return (copy);
			}

			//arithmetic operators
			iterator operator+(int right_hand_side)
			{
				return (iterator(this->_pointer + right_hand_side));
			}
			iterator operator-(int right_hand_side)
			{
				return (iterator(this->_pointer - right_hand_side));
			}
			iterator& operator+=(int right_hand_side)
			{
				this->_pointer += right_hand_side;
				return (*this);
			}
			iterator& operator-=(int right_hand_side)
			{
				this->_pointer -= right_hand_side;
				return (*this);
			}

			//arithmetic operators iter-iter
			int operator+(const iterator& right_hand_side)
			{
				return (this->_pointer + right_hand_side._pointer);
			}
			int operator-(const iterator& right_hand_side)
			{
				return (this->_pointer - right_hand_side._pointer);
			}

			//dereference operator
			reference	operator[](const int n) const {return (this->_pointer[n]);}
			reference	operator*(void) const {return *(this->_pointer);}
			pointer		operator->(void) {return (this->_pointer);}
	};
	
	//Non-member functions
	
	//compares the underlying iterators
	template<class T>
	bool operator==(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class T>
	bool operator!=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class T>
	bool operator<(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class T>
	bool operator<=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class T>
	bool operator>(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class T>
	bool operator>=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	//able comparison of reverse and const_reverse
	template<class T_L, class T_R>
	bool operator==(const ft::random_access_iterator<T_R>& lhs, const ft::random_access_iterator<T_L>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class T_L, class T_R>
	bool operator!=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class T_L, class T_R>
	bool operator<(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class T_L, class T_R>
	bool operator<=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class T_L, class T_R>
	bool operator>(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class T_L, class T_R>
	bool operator>=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

}

#endif
