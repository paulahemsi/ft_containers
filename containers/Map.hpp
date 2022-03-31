/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:16 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/30 22:45:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "rb_tree.hpp"
#include "pair.tpp"
#include "map_iterator.hpp"

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
            typedef ft::map_iterator< ft::map<key_type, mapped_type> >  iterator;
            typedef ft::map_iterator< ft::map<key_type, mapped_type> >  const_iterator;
            // typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
        
		private:
			key_compare							_compare;
			allocator_type						_allocator;
			ft::btree<const key_type, mapped_type>	*_root;

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
			
			ft::pair<int, bool> insert (const value_type& val) //! ITERATOR E BOOL
			{
				(void)val;
				ft::pair<int, int> my_return(1, true);
				btree_insert_data<const key_type, mapped_type, key_compare>(&_root, &val);
				return my_return;
			}

			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);

    };
}

#endif
