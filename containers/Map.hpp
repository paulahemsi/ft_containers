/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:16 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/03 12:27:33 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "rb_tree.hpp"
#include "pair.tpp"
#include "map_iterator.hpp"

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
            // typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
        
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

			ft::pair<int, bool> insert (const value_type& val) //! ITERATOR E BOOL
			{
				ft::pair<int, int> my_return(1, true);
				btree_insert_data(&_root, &val, &_compare_value_type<value_type, Compare>);
				return my_return;
			}

			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);

    };
}

#endif
