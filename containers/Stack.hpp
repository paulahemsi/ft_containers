/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:25:37 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 12:39:24 by phemsi-a         ###   ########.fr       */
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

		protected:
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
			
			size_type size(void) const
			{
				return (this->_container.size());
			}

			void pop(void)
			{
				this->_container.pop_back();
			}

			void push (const value_type& val)
			{
				this->_container.push_back(val);
			}
			
			reference top(void)
			{
				return (this->_container.back());
			}
			
			const_reference top(void) const
			{
				return (this->_container.back());
			}
			
			bool empty() const
			{
				return (this->_container.empty());
			}

			bool operator == (const value_type & other)
			{
				return (this->_container == other->_container);
			}

			bool operator < (const value_type & other)
			{
				return (this->_container < other->_container);
			}
	};
	
	template<class T, class Container > bool operator == (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs == rhs);
	} 
	
	template<class T, class Container > bool operator != (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template<class T, class Container > bool operator < (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs < rhs);
	}
	
	template<class T, class Container > bool operator <= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return ((lhs < rhs) || (lhs == rhs));
	}
	
	template<class T, class Container > bool operator > (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		if (lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	}
	
	template<class T, class Container > bool operator >= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return ((lhs > rhs) || (lhs == rhs));
	}
}

#endif
