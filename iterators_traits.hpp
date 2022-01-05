/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:53:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/04 19:31:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

template <class T>
struct iterator_traits {
	typedef typename T::value_type			value_type;
	typedef typename T::difference_type		difference_type;
	typedef typename T::iterator_category	iterator_category;
	typedef typename T::pointer				pointer;
	typedef typename T::reference			reference;
};

template <typename T>
struct iterator_traits<T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::ptrdiff_t					difference_type;
};

template <class T>
class iterator_traits<const T*>
{
	typedef std::random_access_iterator_tag	iterator_category;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::ptrdiff_t					difference_type;
};

#endif
