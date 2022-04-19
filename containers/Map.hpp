/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:16 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/18 21:26:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "rb_tree.hpp"
#include "pair.tpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.tpp"

namespace ft
{
	template<class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key 																key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const key_type, mapped_type>								value_type;
			typedef std::size_t															size_type;
			typedef std::ptrdiff_t														difference_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename Alloc::pointer												pointer;
			typedef typename Alloc::const_pointer										const_pointer;
			typedef ft::map_iterator<value_type>										iterator;
			typedef ft::map_iterator<value_type>										const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef typename Alloc::template rebind< ft::btree<value_type> >::other		node_allocator_type;

			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;

				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

				public:

				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			};

		private:
			size_type				_size;
			key_compare				_compare;
			allocator_type			_allocator;
			node_allocator_type		_node_allocator;
			ft::btree<value_type>	*_root;

			bool _position_precedes_val(iterator position, const value_type& val)
			{
				return (this->upper_bound(val.first)-- == position);
			}

			value_type * _allocate_pair(const value_type& val)
			{
				value_type *new_pair = this->_allocator.allocate(1);
				this->_allocator.construct(new_pair, val);
				return (new_pair);
			}

		public:
            explicit map (const key_compare& comp = key_compare(),
                          const allocator_type& alloc = allocator_type()):
			_size(0),
			_compare(comp),
			_allocator(alloc),
			_node_allocator(node_allocator_type()),
			_root(NULL) {}
			
			template <class InputIterator>
  			map (InputIterator first,
			  	 InputIterator last,
       			 const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type()):
			_size(0),
			_compare(comp),
			_allocator(alloc),
			_node_allocator(node_allocator_type()),
			_root(NULL)
			{
				this->insert(first, last);
			}
			
			map (const map& other):
			_size(0),
			_compare(other.key_comp()),
			_allocator(other.get_allocator()),
			_node_allocator(node_allocator_type()),
			_root(NULL)
			{
				*this = other;	
			}
			
			~map (void)
			{
				this->clear();
			}

			map& operator= (const map& other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
				return (*this);
			}

			key_compare key_comp(void) const
			{
				return (_compare);
			}
			
			iterator begin(void)
			{
				return iterator(btree_begin(_root));
			}
			
			const_iterator begin(void) const
			{
				return iterator(btree_begin(_root));
			}
			
			iterator end(void)
			{
				return iterator(btree_end(_root));
			}
			
			const_iterator end(void) const
			{
				return iterator(btree_end(_root));
			}

			reverse_iterator rbegin(void) const
			{
				return reverse_iterator(this->end());
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(this->begin());
			}

			size_type size(void) const
			{
				return (this->_size);
			}

			bool	empty(void) const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			ft::pair<iterator, bool> insert (const value_type& val)
			{
				iterator it = this->find(val.first);
				if (it != this->end())
					return (ft::make_pair(it, false));
				btree_insert_data(&_root, _allocate_pair(val), value_compare(this->_compare), _node_allocator);
				it = this->find(val.first);
				this->_size++;
				return (ft::make_pair(it, true));
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				iterator it = this->find(val.first);
				if (it != this->end())
					return (it);
				if (!_position_precedes_val(position, val))
					return (this->insert(val).first);
				ft::btree<value_type> *position_node = position.get_node();
				btree_insert_data<value_type>(&position_node, _allocate_pair(val), value_compare(this->_compare), _node_allocator);
				update_root(&(this->_root));
				it = this->find(val.first);
				this->_size++;
				return (it);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
					this->insert(*first++);
			}

			iterator find (const key_type& k)
			{
				ft::btree<value_type> *k_node;
				k_node = btree_search_node<value_type>(_root, ft::make_pair(k, mapped_type()), value_compare(this->_compare));
				if (k_node)
					return iterator(k_node);
				return iterator(btree_end(_root));
			}

			const_iterator find (const key_type& k) const
			{
				ft::btree<value_type> *k_node;
				k_node = btree_search_node(_root, ft::make_pair(k, mapped_type()), value_compare(this->_compare));
				if (k_node)
					return const_iterator(k_node);
				return const_iterator(btree_end(_root));
			}

			void erase (iterator position)
			{
				value_type *pair_erased = btree_delete<value_type>(&_root, *position, value_compare(this->_compare), _node_allocator);
				this->_allocator.deallocate(pair_erased, 1);
				this->_size--;
			}

			size_type erase (const key_type& key)
			{
				value_type *pair_erased = btree_delete<value_type>(&_root, ft::make_pair(key, mapped_type()), value_compare(this->_compare), _node_allocator);
				if (!pair_erased)
					return (0);
				this->_allocator.deallocate(pair_erased, 1);
				this->_size--;
				return (1);
			}

			void erase (iterator first, iterator last)
			{
				iterator	temp;
				value_type	*next_item;

				while (first != last)
				{
					temp = first;
					next_item = &(*(++temp));
					this->erase(first);
					if (next_item)
						first = find(next_item->first);
					else
						first = last;
				}
			}

			allocator_type get_allocator() const { return (this->_allocator);}

			mapped_type& operator[] (const key_type& key)
			{
				iterator					value_iterator;
				ft::pair<iterator, bool>	insert_return;

				insert_return = insert(ft::make_pair(key, mapped_type()));
				value_iterator = insert_return.first;
				return (value_iterator->second);
			}

			iterator lower_bound (const key_type& key)
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);
				value_type boundary_pair = ft::make_pair(key, mapped_type());

				while(node != end_node)
				{
					if (this->value_comp()(*node->item, boundary_pair))
						node = btree_next(node);
					else
						return iterator(node);
				}
				return (iterator(end_node));
			}

			const_iterator lower_bound (const key_type& key) const
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);
				value_type boundary_pair = ft::make_pair(key, mapped_type());

				while(node != end_node)
				{
					if (this->value_comp()(*node->item, boundary_pair))
						node = btree_next(node);
					else
						return const_iterator(node);
				}
				return (const_iterator(end_node));
			}
			
			iterator upper_bound (const key_type& key)
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);
				value_type boundary_pair = ft::make_pair(key, mapped_type());

				while(node != end_node)
				{
					if (this->value_comp()(boundary_pair, *node->item))
						return iterator(node);
					else
						node = btree_next(node);
				}
				return (iterator(end_node));
			}

			const_iterator upper_bound (const key_type& key) const
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);
				value_type boundary_pair = ft::make_pair(key, mapped_type());

				while(node != end_node)
				{
					if (this->value_comp()(boundary_pair, *node->item))
						return const_iterator(node);
					else
						node = btree_next(node);
				}
				return (const_iterator(end_node));
			}

			//The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& key) const
			{
				return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
			}

			ft::pair<iterator,iterator> equal_range (const key_type& key)
			{
				return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
			}

			size_type count (const key_type& key) const
			{
				if (btree_search_node<value_type>(_root, ft::make_pair(key, mapped_type()), value_compare(this->_compare)))
					return (1);
				return (0);
			}

			value_compare	value_comp(void) const
			{
				return (value_compare(_compare));
			}

			size_type max_size(void) const
			{
				return (_node_allocator.max_size());
			}

			void clear(void)
			{
				this->erase(this->begin(), this->end());
				this->_root = NULL;
			}

			void swap (map& other)
			{
				ft::btree<value_type>	*root_tmp;
				size_t					size_tmp;

				root_tmp = other._root;
				other._root = this->_root;
				this->_root = root_tmp;

				size_tmp = other._size;
				other._size = this->_size;
				this->_size = size_tmp;
			}
	};

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const map<Key, T, Compare, Alloc> &lhs,
					 const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const map<Key, T, Compare, Alloc> &lhs,
					 const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return ((lhs > rhs) || (lhs == rhs));
	}
};


#endif
