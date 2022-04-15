/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:25:37 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 10:48:47 by phemsi-a         ###   ########.fr       */
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
		private:

			typedef	Container					container_type
			typedef	Container::value_type		value_type
			typedef	Container::size_type		size_type
			typedef	Container::reference		reference
			typedef	Container::const_reference	const_reference

		public:
		
		explicit stack( const Container& cont = Container() );

		stack( const stack& other );
		
		~stack();
		
		stack& operator=( const stack& other );
	};
}

#endif
