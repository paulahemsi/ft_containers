/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/03 13:17:06 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

#include "rb_tree.hpp"

namespace ft {
	
	template <typename T>
	class map_iterator
	{
		public:

			typedef	map_iterator<T>	iterator;
			typedef T				value_type;
			typedef const T*		pointer; //CONST?
			typedef const T&		reference; //CONST?
			typedef ft::btree<T>*	node_pointer;
			typedef ft::btree<T>&	node_reference;
			typedef std::ptrdiff_t	difference_type;
		
		private:
			node_pointer	_node_pointer;
			
		public:
		
			//canonical
			map_iterator(): _node_pointer(NULL) {};
			explicit map_iterator(node_pointer ptr): _node_pointer(ptr) {}
			map_iterator(const map_iterator& instance) {*this = instance;}
			~map_iterator() {};
			map_iterator& operator=(const map_iterator& right_hand_side)
			{
				this->_node_pointer = right_hand_side._node_pointer;
				return *this;
			}

			//relational operators overload
			bool operator==(const iterator& right_hand_side)
			{
				return this->_node_pointer == right_hand_side._node_pointer;
			}
			bool operator!=(const iterator& right_hand_side)
			{
				return this->_node_pointer != right_hand_side._node_pointer;
			}

			//increment and decrement
			iterator& operator++(void)
			{
				this->_node_pointer = btree_next(this->_node_pointer);
				return (*this);
			}
			iterator& operator--(void)
			{
				this->_node_pointer = btree_previous(this->_node_pointer);
				return (*this);
			}
			iterator operator++(int)
			{
				iterator copy(*this);
				this->_node_pointer = btree_next(this->_node_pointer);
				return (copy);
			}
			iterator operator--(int)
			{
				iterator copy(*this);
				this->_node_pointer = btree_previous(this->_node_pointer);
				return (copy);
			}

			//dereference operator
			reference	operator*(void) const
			{
				return *(this->_node_pointer->item);
			}
			pointer		operator->(void)
			{
				return (this->_node_pointer->item);
			}
	};
}

#endif
