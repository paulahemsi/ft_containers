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

			typedef	typename Container::value_type		value_type;
			typedef	Container							container_type;
			typedef	typename Container::size_type		size_type;
			typedef	typename Container::reference		reference;
			typedef	typename Container::const_reference	const_reference;

			template< class T2, class Container2>
			friend bool operator == (const ft::stack<T2, Container2> & lhs, const ft::stack<T2, Container2> & rhs);

			template< class T2, class Container2>
			friend bool operator < (const ft::stack<T2, Container2> & lhs, const ft::stack<T2, Container2> & rhs);

		protected:
			container_type	c;
			
		public:

			explicit stack( const container_type& cont = container_type() ): c(cont) {}

			stack( const stack& other ): c(other.c) {}

			~stack() {}

			stack& operator=( const stack& other )
			{ 
				c = other.c;
				return (*this);
			}
			
			bool empty() const
			{
				return (this->c.empty());
			}
			
			size_type size(void) const
			{
				return (this->c.size());
			}
			
			reference top(void)
			{
				return (this->c.back());
			}

			const_reference top(void) const
			{
				return (this->c.back());
			}

			void push (const value_type& val)
			{
				this->c.push_back(val);
			}

			void pop(void)
			{
				this->c.pop_back();
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
