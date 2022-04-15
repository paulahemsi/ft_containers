/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:25:37 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 11:19:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			typedef	Container							container_type;
			typedef	typename Container::value_type		value_type;
			typedef	typename Container::size_type		size_type;
			typedef	typename Container::reference		reference;
			typedef	typename Container::const_reference	const_reference;

		private:
			container_type						_container;
			
		public:

			explicit stack( const Container& cont = Container() ): _container(cont) {}

			stack( const stack& other ): _container(other._container) {}

			~stack() {}

			stack& operator=( const stack& other )
			{ 
				_container = other._container;
				return (*this);
			}
	};
}

#endif
