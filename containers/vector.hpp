/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:11:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/04/22 18:06:39 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <exception>
#include "type_traits.tpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.tpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			size_type	_size;
			size_type	_capacity;
			Alloc		_allocator;
			pointer		_array;
			
			void	_checkOutOfBounds(size_type pos)
			{
				if (pos >= this->_size)
					throw OutOfBoundsException(pos);
			}

			void	_reAlloc(size_type newCapacity)
			{
				value_type	*newBlock;

				if (newCapacity < this->_capacity)
					return ;
				newBlock = this->_allocator.allocate(newCapacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&newBlock[i], this->_array[i]);
				this->_allocator.deallocate(this->_array, this->_capacity);
				this->_array = newBlock;
				this->_capacity = newCapacity;
			}

			void	_smart_reAlloc(size_type newCapacity)
			{
				if (newCapacity <= this->_capacity)
					return ;
				if (this->_size == 0)
					this->_reAlloc(1);
				else if(newCapacity > (this->_size * 2))
					this->_reAlloc(newCapacity);
				else
					this->_reAlloc(this->_size * 2);
			}

			void _open_space(size_type n, size_type index_to_insert)
			{
				this->_smart_reAlloc(this->_size + n);
				for (size_type i = this->_size + n - 1; i > (index_to_insert + n - 1); i--)
					this->_allocator.construct(&this->_array[i], this->_array[i - n]);
			}

		public:

			explicit vector (const allocator_type& alloc = allocator_type()):
				_size(0),
				_capacity(0),
				_allocator(alloc),
				_array(NULL) {}

			explicit vector(size_type n,
							const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()):
				_size(n),
				_capacity(n),
				_allocator(alloc),
				_array(this->_allocator.allocate(this->_capacity))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_array[i], val);
			}

			template <class InputIterator>
			vector(InputIterator first,
					InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 666):
				_size(last - first),
				_capacity(last - first),
				_allocator(alloc),
				_array(this->_allocator.allocate(this->_size))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_array[i], *(first + i));
			}

			vector(const vector& other):
				_size(0),
				_capacity(0),
				_allocator(other._allocator),
				_array(NULL)
			{
				*this = other;
			}

			~vector()
			{
				this->_allocator.deallocate(this->_array, this->_capacity);
			}

			vector&	operator=(const vector& other)
			{
				this->clear();
				this->_reAlloc(other._size);
				for (size_type i = 0; i < other._size; i++)
					this->_allocator.construct(&this->_array[i], other._array[i]);
				this->_size = other._size;
				return (*this);
			}

			iterator begin(void)
			{
				return iterator(this->_array);
			}

			const_iterator begin(void) const
			{
				return const_iterator(this->_array);
			}

			iterator end(void)
			{
				return iterator(this->_array + this->_size);
			}

			const_iterator end(void) const
			{
				return const_iterator(this->_array + this->_size);
			}

			reverse_iterator rbegin(void)
			{
				return reverse_iterator(--this->end());
			}

			const_reverse_iterator rbegin(void) const
			{
				return const_reverse_iterator(--this->end());
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(--this->begin());
			}

			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(--this->begin());
			}

			size_type size(void) const
			{
				return (this->_size);
			}

			size_type max_size(void) const
			{
				return (this->_allocator.max_size());
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n == this->_size)
					return ;
				if (n < this->_size)
					for (size_type i = n; i <= this->_size; i++)
						this->_allocator.destroy(&this->_array[i]);
				else
				{
					this->_reAlloc(n);
					for (size_type i = this->_size; i < n; i++)
						this->_allocator.construct(&this->_array[i], val);
				}
				this->_size = n;
			}
			
			size_type capacity(void) const
			{
				return (this->_capacity);
			}

			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			void reserve(size_type n)
			{
				this->_reAlloc(n);
			}

			reference	operator[](size_type pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_array[pos]);
			}

			const_reference operator[] (size_type pos) const
			{
				this->_checkOutOfBounds(pos);
				return (this->_array[pos]);
			}

			reference	at(size_type pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_array[pos]);
			}

			reference	front(void)
			{
				return (this->_array[0]);
			}

			const_reference	front(void) const
			{
				return (this->_array[0]);
			}
			
			reference	back(void)
			{
				return (this->_array[this->_size - 1]);
			}

			const_reference	back(void) const
			{
				return (this->_array[this->_size - 1]);
			}

			template< class InputIt >
			void assign(InputIt first,
						InputIt last,
						typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = false)
			{
				if (this->_array)
					this->_allocator.deallocate(this->_array, this->_capacity);
				this->_size = last - first;
				if (this->_capacity < this->_size)
					this->_capacity = this->_size;
				this->_array = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_array[i], *(first + i));
			}
			
			void assign(size_type count, const value_type& value)
			{
				if (this->_array)
					this->_allocator.deallocate(this->_array, this->_capacity);
				this->_size = count;
				if (this->_capacity < this->_size)
					this->_capacity = this->_size;
				this->_array = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_array[i] = value;
			}

			void push_back(const value_type& value)
			{
				this->_smart_reAlloc(this->_size + 1);
				this->_allocator.construct(&this->_array[this->_size], value);
				this->_size++;
			}

			void pop_back(void)
			{
				if (this->_size == 0)
					return ;
				this->_allocator.destroy(this->_array + this->_size - 1);
				this->_size--;
			}
			
			iterator insert(iterator position, const value_type& val)
			{
				size_type index_to_insert = position - this->begin();

				this->_open_space(1, index_to_insert);
				this->_allocator.construct(&this->_array[index_to_insert], val);
				this->_size++;
				return (this->begin() + index_to_insert);
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type index_to_insert = position - this->begin();

				this->_open_space(n, index_to_insert);
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(&this->_array[index_to_insert + i], val);
				this->_size += n;
			}
			
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 666)
			{
				size_type index_to_insert = position - this->begin();
				size_type n = last - first;

				this->_open_space(n, index_to_insert);
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(&this->_array[index_to_insert + i], *(first + i));
				this->_size += n;
			}

			iterator erase(iterator position)
			{
				iterator iter = position;
				
				this->_allocator.destroy(&(*position));
				while (iter != (this->end() - 1))
					this->_allocator.construct(&(*iter), *(++iter));
				this->_size--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				for (size_type i = 0; (last + i) != this->end(); i++)
				{
					this->_allocator.destroy(&(*(first + i)));
					this->_allocator.construct(&(*(first + i)), *(last + i));
				}
				this->_size -= last - first;
				return(first);
			}
			
			void swap(vector& other)
			{
				size_type	temp_size = other._size;
				size_type	temp_capacity = other._capacity;
				Alloc		temp_allocator = other._allocator;
				pointer		temp_array = other._array;

				other._size = this->_size;
				other._capacity = this->_capacity;
				other._allocator = this->_allocator;
				other._array = this->_array;

				this->_size = temp_size;
				this->_capacity = temp_capacity;
				this->_allocator = temp_allocator;
				this->_array = temp_array;
			}
			
			void clear(void)
			{
				this->_allocator.destroy(this->_array);
				this->_size = 0;
			}

			allocator_type get_allocator() const
			{
				return (this->_allocator);
			}

			class OutOfBoundsException : public std::exception
			{
				size_t _pos;

				public:
					OutOfBoundsException(int pos) : _pos(pos){}
					virtual const char* what() const throw()
					{
						return ("vector::_M_range_check: index >= this->_size()");
					}
			};
	};

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

	template <class T, class Alloc>
	bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs > rhs) || (lhs == rhs));
	}
}

#endif
