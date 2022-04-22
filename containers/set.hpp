/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:07:36 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/22 16:21:37 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <functional>
#include "rb_tree.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.tpp"

namespace ft
{
	template<
			class Key,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<Key> > 
	class set
	{
		public:
			typedef Key 																key_type;
			typedef Key 																value_type;
			typedef std::size_t															size_type;
			typedef std::ptrdiff_t														difference_type;
			typedef Compare																key_compare;
			typedef Compare																value_compare;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename Alloc::pointer												pointer;
			typedef typename Alloc::const_pointer										const_pointer;
			typedef ft::map_iterator<value_type>										iterator;
			typedef ft::map_iterator<value_type>										const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

		private:
			size_type				_size;
			key_compare				_compare;
			allocator_type			_allocator;
			ft::btree<value_type>	*_root;

			bool _position_precedes_val(iterator position, const value_type& val)
			{
				return (this->upper_bound(val)-- == position);
			}

			value_type * _allocate_value(const value_type& val)
			{
				value_type *new_key = this->_allocator.allocate(1);
				this->_allocator.construct(new_key, val);
				return (new_key);
			}

		public:
		
			set(void):
				_size(0),
				_compare(Compare()),
				_allocator(Alloc()),
				_root(NULL) {}

			explicit set( const Compare& comp, const Alloc& alloc = Alloc() ):
				_size(0),
				_compare(comp),
				_allocator(alloc),
				_root(NULL) {}
			
			template <class InputIterator>
			set( InputIterator first,
				 InputIterator last,
				 const Compare& comp = Compare(),
				 const Alloc& alloc = Alloc() ):
			_size(0),
			_compare(comp),
			_allocator(alloc),
			_root(NULL)
			{
				this->insert(first, last);
			}
			
			set (const set& other):
			_size(0),
			_compare(other.key_comp()),
			_allocator(other.get_allocator()),
			_root(NULL)
			{
				*this = other;	
			}
			
			~set (void)
			{
				this->clear();
			}

			set& operator= (const set& other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
				return (*this);
			}
			
			allocator_type get_allocator() const { return (this->_allocator);}
			
			iterator begin(void)
			{
				return iterator(btree_begin(_root));
			}
			
			const_iterator begin(void) const
			{
				return const_iterator(btree_begin(_root));
			}

			iterator end(void)
			{
				return iterator(btree_end(_root));
			}
			
			const_iterator end(void) const
			{
				return const_iterator(btree_end(_root));
			}

			reverse_iterator rbegin(void) const
			{
				return reverse_iterator(--this->end());
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(--this->begin());
			}
			
			// const_reverse_iterator rbegin(void) const
			// {
			// 	return const_reverse_iterator(this->end());
			// }

			// const_reverse_iterator rend(void)
			// {
			// 	return const_reverse_iterator(this->begin());
			// }

			bool	empty(void) const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			size_type size(void) const
			{
				return (this->_size);
			}

			size_type max_size(void) const
			{
				return (_allocator.max_size());
			}

			void clear(void)
			{
				this->erase(this->begin(), this->end());
				this->_root = NULL;
			}

			ft::pair<iterator, bool> insert (const value_type& val)
			{
				iterator it = this->find(val);
				if (it != this->end())
					return (ft::make_pair(it, false));
				btree_insert_data(&_root, _allocate_value(val), this->_compare, std::allocator<ft::btree<value_type> >() );
				it = this->find(val);
				this->_size++;
				return (ft::make_pair(it, true));
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				iterator it = this->find(val);
				if (it != this->end())
					return (it);
				if (!_position_precedes_val(position, val))
					return (this->insert(val).first);
				ft::btree<value_type> *position_node = position.get_node();
				btree_insert_data<value_type>(&position_node, _allocate_value(val), this->_compare, std::allocator<ft::btree<value_type> >() );
				update_root(&(this->_root));
				it = this->find(val);
				this->_size++;
				return (it);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
					this->insert(*first++);
			}

			void erase (iterator position)
			{
				value_type *value_erased = btree_delete<value_type>(&_root, *position, this->_compare, std::allocator<ft::btree<value_type> >() );
				this->_allocator.deallocate(value_erased, 1);
				this->_size--;
			}

			size_type erase (const Key& key)
			{
				value_type *value_erased = btree_delete<value_type>(&_root, key, this->_compare, std::allocator<ft::btree<value_type> >() );
				if (!value_erased)
					return (0);
				this->_allocator.deallocate(value_erased, 1);
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
						first = find(*next_item);
					else
						first = last;
				}
			}

			void swap (set& other)
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
			
			size_type count (const Key& key) const
			{
				if (btree_search_node<value_type>(_root, key, this->_compare))
					return (1);
				return (0);
			}

			iterator find (const Key& key)
			{
				ft::btree<value_type> *key_node;
				key_node = btree_search_node<value_type>(_root, key, this->_compare);
				if (key_node)
					return iterator(key_node);
				return iterator(btree_end(_root));
			}

			const_iterator find (const Key& key) const
			{
				ft::btree<value_type> *key_node;
				key_node = btree_search_node(_root, key, this->_compare);
				if (key_node)
					return const_iterator(key_node);
				return const_iterator(btree_end(_root));
			}

			ft::pair<iterator,iterator> equal_range (const Key& key)
			{
				return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
			}

			ft::pair<const_iterator,const_iterator> equal_range (const Key& key) const
			{
				return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
			}

			iterator lower_bound (const Key& key)
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);

				while(node != end_node)
				{
					if (this->_compare(*node->item, key))
						node = btree_next(node);
					else
						return iterator(node);
				}
				return (iterator(end_node));
			}

			const_iterator lower_bound (const Key& key) const
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);

				while(node != end_node)
				{
					if (this->_compare(*node->item, key))
						node = btree_next(node);
					else
						return const_iterator(node);
				}
				return (const_iterator(end_node));
			}
			
			iterator upper_bound (const Key& key)
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);

				while(node != end_node)
				{
					if (this->_compare(key, *node->item))
						return iterator(node);
					else
						node = btree_next(node);
				}
				return (iterator(end_node));
			}

			const_iterator upper_bound (const Key& key) const
			{
				ft::btree<value_type> *end_node = btree_end(this->_root);
				ft::btree<value_type> *node = btree_begin(this->_root);

				while(node != end_node)
				{
					if (this->_compare(key, *node->item))
						return const_iterator(node);
					else
						node = btree_next(node);
				}
				return (const_iterator(end_node));
			}

			key_compare key_comp(void) const
			{
				return (this->_compare);
			}
	
			value_compare	value_comp(void) const
			{
				return (this->_compare);
			}

	};

	template <class Key, class Compare, class Alloc>
	void swap (set<Key,Compare,Alloc>& x, set<Key,Compare,Alloc>& y)
	{
		x.swap(y);
	}

	template <class Key, class Compare, class Alloc>
	bool operator== (const set<Key, Compare, Alloc> &lhs,
					 const set<Key, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator!= (const set<Key, Compare, Alloc> &lhs,
					 const set<Key, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<  ( const set<Key, Compare,Alloc>& lhs,
					const set<Key, Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<= ( const set<Key, Compare,Alloc>& lhs,
					const set<Key, Compare,Alloc>& rhs )
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class Key, class Compare, class Alloc>
	bool operator>  ( const set<Key, Compare,Alloc>& lhs,
					const set<Key, Compare,Alloc>& rhs )
	{
		if (lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	}

	template <class Key, class Compare, class Alloc>
	bool operator>= ( const set<Key, Compare,Alloc>& lhs,
					const set<Key, Compare,Alloc>& rhs )
	{
		return ((lhs > rhs) || (lhs == rhs));
	}
};


#endif
