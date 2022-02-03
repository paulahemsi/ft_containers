/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:11:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/02 19:53:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "type_traits.hpp"
#include "random_access_iterator.hpp"

namespace ft {

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
			//typedef ft::reverse_iterator<iterator>			reverse_iterator;
			//typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
			
		private:
			size_type	_size;
			size_type	_capacity;
			Alloc		_allocator;
			pointer		_data;
			
			void	_checkOutOfBounds(int pos)
			{
				if(pos < 0 || pos >= static_cast<int>(this->_size))
					throw OutOfBoundsException(pos);
			}

			void	_reAlloc(size_type newCapacity)
			{
				value_type	*newBlock = this->_allocator.allocate(newCapacity);

				if(newCapacity < this->_size)
					this->_size = newCapacity;
				for(size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&newBlock[i], this->_data[i]);
				this->_allocator.deallocate(this->_data, this->_capacity);
				_data = newBlock;
				_capacity = newCapacity;
			}
		public:
			//empty container constructor (default constructor)
			//Constructs an empty container, with no elements.
			explicit vector (const allocator_type& alloc = allocator_type()):
																			_size(0),
																			_capacity(0),
																			_allocator(alloc),
																			_data(NULL) {}
			//fill constructor
			//Constructs a container with n elements. Each element is a copy of val.
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
								_size(n),
								_capacity(n),
								_allocator(alloc),
								_data(this->_allocator.allocate(this->_capacity))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i], val);
			}
			//range constructor
			//Constructs a container with as many elements as the range [first,last], with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false):
																											_size(last - first),
																											_capacity(last - first),
																											_allocator(alloc),
																											_data(this->_allocator.allocate(this->_size))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i], *(first + i));
			}
			//copy constructor
			//Constructs a container with a copy of each of the elements in other, in the same order
			vector(const vector&	other):
											_size(other._size),
											_capacity(other._capacity),
											_data(this->_allocator.allocate(this->_capacity))
			{
				*this = other;
			}
			~vector()
			{
				this->_allocator.deallocate(this->_data, this->_capacity);
			}

			vector&	operator=(const vector& other)
			{
				if (this->_capacity < other._size)
					this->_reAlloc(other._size);
				for(size_type i = 0; i < other._size; i++)
					this->_allocator.construct(&this->_data[i], other._data[i]);
				return (*this);
			}

			reference	operator[](int pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_data[pos]);
			}

			iterator begin(void)
			{
				return iterator(this->_data);
			}

			iterator end(void)
			{
				return iterator(this->_data + this->_size);
			}

			const_iterator begin(void) const
			{
				return const_iterator(this->_data);
			}

			const_iterator end(void) const
			{
				return const_iterator(this->_data + this->_size);
			}

			iterator rbegin(void)
			{
				return iterator(this->_data + this->size - 1);
			}

			iterator rend(void)
			{
				return iterator(this->_data - 1);
			}

			const reference	operator[](int pos) const
			{
				this->_checkOutOfBounds(pos);
				return (this->_data[pos]);
			}
			
			reference	at(int pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_data[pos]);
			}
			
			reference	front(void)
			{
				return (this->_data[0]);
			}
			
			reference	back(void)
			{
				return (this->_data[this->_size - 1]);
			}
			
			void push_back(const value_type& value)
			{
				if(this->_size == this->_capacity)
				{
					if(this->_capacity == 0)
					{
						this->_capacity = 1;
						this->_reAlloc(this->_capacity);
					}
					else
						this->_reAlloc(this->_capacity * 2);
				}
				this->_allocator.construct(&this->_data[this->_size], value);
				this->_size++;
			}

			void pop_back(void)
			{
				this->_data[this->_size - 1] = 0;
				this->_size--;
			}

			size_type size(void) const
			{
				return (this->_size);
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

			void assign(size_type count, const value_type& value)
			{
				if (this->_data)
					this->_allocator.deallocate(this->_data, this->_capacity);
				this->_size = count;
				if (this->_capacity < this->_size)
					this->_capacity = this->_size;
				this->_data = this->_allocator.allocate(this->_capacity);
				for(size_type i = 0; i < this->_size; i++)
					this->_data[i] = value;
			}

			// template< class InputIt >
			// void assign(InputIt first, InputIt last)
			// {
				
			// }

			//!Dá diferença pro workspace
			// void resize(size_type count, value_type value = value_type())
			// {
				
			// }

			//size_type max_size() const;
			size_type max_size(void) const
			{
				return (this->_allocator.max_size());
			}

			//allocator_type get_allocator() const;
			allocator_type get_allocator(void) const
			{
				return (this->_allocator);
			}

			class OutOfBoundsException : public std::exception
			{
				int _pos;

				public:
					OutOfBoundsException(int pos) : _pos(pos){}
					virtual const char* what() const throw()
					{
						if(this->_pos < 0)
							return ("vector::_M_range_check: index < 0");
						return ("vector::_M_range_check: index >= this->_size()");
					}
			};
		//* operator= ok
		// HALF assign ok
		// resize ok
		// * get_allocator como usa??
		//* at ok
		//* operator[] ok
		//* front ok
		//* back ok
		// begin
		// end 
		// rbegin
		// rend
		// data
		// * empty ok
		// * size ok
		// * max_size ok
		// reserve?
		//* capacity
		// shrink_to_fit
		// clear 
		// insert
		// erase
		//* push_back
		//* pop_back
		// swap
	};
}

