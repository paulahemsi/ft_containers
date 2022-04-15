/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:25:37 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/15 13:08:24 by phemsi-a         ###   ########.fr       */
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

			template< class T2, class Container2>
			friend bool operator == (const ft::stack<T2, Container2> & lhs, const ft::stack<T2, Container2> & rhs);

			template< class T2, class Container2>
			friend bool operator < (const ft::stack<T2, Container2> & lhs, const ft::stack<T2, Container2> & rhs);

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
	};
	
	template<class T, class Container >
	bool operator == (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs._container == rhs._container);
	} 
	
	template<class T, class Container > bool operator != (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template<class T, class Container > bool operator < (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs._container < rhs._container);
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
