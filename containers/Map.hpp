/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:16 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/07 21:48:43 by phemsi-a         ###   ########.fr       */
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

template<class T, class T2>
int	_compare_value_type(const T *pair1, const T *pair2)
{
	T2 _compare;
	if (pair1->first == pair2->first)
		return (0);
	if (_compare(pair1->first, pair2->first))
		return (-1);
	return (1);
}

namespace ft
{
    template<class Key,
             class T,
             class Compare = std::less<Key>,
             class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public:
			typedef Key 											    key_type;
			typedef T												    mapped_type;
			typedef ft::pair<const key_type, mapped_type>	            value_type;
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;
            typedef Compare                                             key_compare;
            typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
            typedef typename Alloc::pointer								pointer;
            typedef typename Alloc::const_pointer						const_pointer;
            typedef ft::map_iterator<value_type>						iterator;
            typedef ft::map_iterator<value_type>						const_iterator;
            typedef ft::reverse_iterator<iterator>						reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
        
		private:
			key_compare				_compare;
			allocator_type			_allocator;
			ft::btree<value_type>	*_root;

			// int	_compare_value_type(const value_type *pair1, const value_type *pair2)
			// {
			// 	if (pair1->first == pair2->first)
			// 		return (0);
			// 	if (_compare(pair1->first, pair2->first))
			// 		return (-1);
			// 	return (1);
			// }

		public:
            explicit map (const key_compare& comp = key_compare(),
                          const allocator_type& alloc = allocator_type()):
			_compare(comp),
			_allocator(alloc),
			_root(NULL) {}
			
			template <class InputIterator>
  			map (InputIterator first,
			  	 InputIterator last,
       			 const key_compare& comp = key_compare(),
       			 const allocator_type& alloc = allocator_type());
			
			map (const map& other)
			{
				*this = other;	
			}
			
			~map (void)
			{
				btree_delete_tree(this->_root);
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

			ft::pair<iterator, bool> insert (const value_type& val)
			{
				iterator it = this->find(val.first);
				if (it != this->end())
					return (ft::make_pair(it, false));
				value_type *new_pair = this->_allocator.allocate(1);
				this->_allocator.construct(new_pair, val);
				btree_insert_data(&_root, new_pair, &_compare_value_type<value_type, Compare>);
				it = this->find(new_pair->first);
				return (ft::make_pair(it, true));
			}

			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);

			iterator find (const key_type& k)
			{
				ft::btree<value_type> *k_node;
				k_node = btree_search_node<value_type>(_root, ft::make_pair(k, mapped_type()), &_compare_value_type<value_type, Compare>);
				if (k_node)
					return iterator(k_node);
				return iterator(btree_end(_root));
			}

			const_iterator find (const key_type& k) const
			{
				ft::btree<value_type> *k_node;
				k_node = btree_search_node(_root, ft::make_pair(k, mapped_type()), &_compare_value_type<value_type, Compare>);
				if (k_node)
					return const_iterator(k_node);
				return const_iterator(btree_end(_root));
			}

			void erase (iterator position)
			{
				value_type *pair_erased = btree_delete<value_type>(&_root, *position, &_compare_value_type<value_type, Compare>);
				if (pair_erased)
					this->_allocator.deallocate(pair_erased, 1);
			}

			size_type erase (const key_type& key)
			{
				value_type *pair_erased = btree_delete<value_type>(&_root, ft::make_pair(key, mapped_type()), &_compare_value_type<value_type, Compare>);
				if (!pair_erased)
					return (0);
				this->_allocator.deallocate(pair_erased, 1);
				return (1);
			}

			void erase (iterator first, iterator last)
			{
				iterator temp;
				key_type next_key;

				while (first != last)
				{
					temp = first;
					next_key = (++temp)->first;
					this->erase(first);
					first = find(next_key);
				}
			}

			allocator_type get_allocator() const { return (this->_allocator);}
	};
}

#endif
