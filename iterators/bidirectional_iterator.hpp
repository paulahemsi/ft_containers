/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/06 20:02:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR
#define BIDIRECTIONAL_ITERATOR

namespace ft {
	
	template <typename T>
	class bidirectional_iterator
	{
		private:
			pointer	_pointer;
			
		public:
			typedef	random_access_iterator<T>	iterator;
		
			//canonical
			random_access_iterator(): _pointer(NULL) {};
			explicit random_access_iterator(pointer ptr): _pointer(ptr) {}
			random_access_iterator(const random_access_iterator& instance) {*this = instance;}
			~random_access_iterator() {};
			random_access_iterator& operator=(const random_access_iterator& right_hand_side)
			{
				this->_pointer = right_hand_side._pointer;
				return *this;
			}

			//relational operators overload
			bool operator==(const iterator& right_hand_side)
			{
				return this->_pointer == right_hand_side._pointer;
			}
			bool operator!=(const iterator& right_hand_side)
			{
				return this->_pointer != right_hand_side._pointer;
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

			//dereference operator
			reference	operator*(void) const {return *(this->_pointer);}
			pointer		operator->(void) {retrun (this->_pointer);}
	};
}

#endif
