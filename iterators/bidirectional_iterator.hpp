/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/09 18:10:21 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR
#define BIDIRECTIONAL_ITERATOR

#include "rb_tree.hpp"

namespace ft {
	
	template <typename T>
	class	bidirectional_iterator
	{
		public:

			typedef	bidirectional_iterator<T>		iterator;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::btree<T>*					node_pointer;
			typedef ft::btree<T>&					node_reference;
			typedef std::ptrdiff_t					difference_type;
		
		private:
			node_pointer	_node_pointer;
			
		public:
		
			//canonical
			bidirectional_iterator(): _node_pointer(NULL) {};
			explicit bidirectional_iterator(node_pointer ptr): _node_pointer(ptr) {}
			bidirectional_iterator(const bidirectional_iterator& instance) {*this = instance;}
			~bidirectional_iterator() {};
			bidirectional_iterator& operator=(const bidirectional_iterator& right_hand_side)
			{
				this->_node_pointer = right_hand_side._node_pointer;
				return *this;
			}

			node_pointer get_node(void)
			{
				return (this->_node_pointer);
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
