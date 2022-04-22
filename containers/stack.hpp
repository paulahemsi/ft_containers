/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:25:37 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/22 15:54:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector.hpp>

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
			container_type						c;
			
		public:

			explicit stack( const Container& cont = Container() ): c(cont) {}

			stack( const stack& other ): c(other.c) {}

			~stack() {}

			stack& operator=( const stack& other )
			{ 
				c = other.c;
				return (*this);
			}
			
			size_type size(void) const
			{
				return (this->c.size());
			}

			void pop(void)
			{
				this->c.pop_back();
			}

			void push (const value_type& val)
			{
				this->c.push_back(val);
			}
			
			reference top(void)
			{
				return (this->c.back());
			}
			
			const_reference top(void) const
			{
				return (this->c.back());
			}
			
			bool empty() const
			{
				return (this->c.empty());
			}
	};
	
	template<class T, class Container >
	bool operator == (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	} 
	
	template<class T, class Container > bool operator != (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template<class T, class Container > bool operator < (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
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
