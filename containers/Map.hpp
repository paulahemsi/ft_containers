/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:16 by lfrasson          #+#    #+#             */
/*   Updated: 2022/03/28 22:10:58 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "pair.tpp"
#include "pair.tpp"

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
			typedef ft::pair<const key_type, mapped_type>	            value_type	
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;
            typedef Compare                                             key_compare;
            typedef Allocator                                           allocator_type;
            typedef typename value_type&                                reference;
            typedef const typename value_type&                          const_reference;
            typedef typename Allocator::pointer                         pointer;
            typedef typename Allocator::const_pointer                   const_pointer;
            typedef ft::map_iterator< ft::map<key_type, mapped_type> >  iterator;
            typedef ft::map_iterator< ft::map<key_type, mapped_type> >  const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;

    };
}

#endif
