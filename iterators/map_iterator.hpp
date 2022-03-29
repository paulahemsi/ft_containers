/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/03/28 22:31:48 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

namespace ft {
	
	template <typename T>
	class map_iterator
	{
		private:
			pointer	_pointer;
			
		public:
			typedef	map_iterator<T>	iterator;
		
			//canonical
			map_iterator(): _pointer(NULL) {};
			explicit map_iterator(pointer ptr): _pointer(ptr) {}
			map_iterator(const map_iterator& instance) {*this = instance;}
			~map_iterator() {};
			map_iterator& operator=(const map_iterator& right_hand_side)
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
