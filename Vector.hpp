/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:11:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/06 20:15:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "random_access_iterator.hpp"

namespace ft {

	// template<typename vector>
	// class vectorIterator
	// {
	// 	private:
	// 		typename vector::T _ptr;

	// 	public:
	// 		// using ValueType = typename vector::ValueType;
	// 		// using PointerType = ValueType*;
	// 		// using ReferenceType = ValueType&;

	// 		vectorIterator(typename vector::T* _data): _ptr(_data) {};

	// 		vectorIterator& operator++(void)
	// 		{
	// 			this->_ptr++;
	// 			return (*this);
	// 		}

	// 		vectorIterator operator++(int)
	// 		{
	// 			typename vector::T iteratorCopy = this;
	// 			this->_ptr++;
	// 			return (*iteratorCopy);
	// 		}

	// 		vectorIterator& operator--(void)
	// 		{
	// 			this->_ptr--;
	// 			return (*this);
	// 		}

	// 		vectorIterator operator--(int)
	// 		{
	// 			typename vector::T iteratorCopy = this;
	// 			this->_ptr--;
	// 			return (*iteratorCopy);
	// 		}

	// 		typename vector::T& operator[](int index)
	// 		{
	// 			return *(this->_ptr + index);
	// 		}

	// 		typename vector::T* operator->(void)
	// 		{
	// 			return (this->_ptr);
	// 		}

	// 		typename vector::T& operator*(int index)
	// 		{
	// 			return (*this->_ptr);
	// 		}

	// 		bool operator==(const vectorIterator& other) const
	// 		{
	// 			return (this->_ptr == other._ptr);
	// 		}

	// 		bool operator!=(const vectorIterator& other) const
	// 		{
	// 			return (this->_ptr != other._ptr);
	// 		}

	// 		bool operator>=(const vectorIterator& other) const
	// 		{
	// 			return (this->_ptr >= other._ptr);
	// 		}

	// 		bool operator<=(const vectorIterator& other) const
	// 		{
	// 			return (this->_ptr <= other._ptr);
	// 		}

	// 		bool operator>(const vectorIterator& other) const
	// 		{
	// 			return (this->_ptr > other._ptr);
	// 		}

	// 		bool operator<(const vectorIterator& other) const
	// 		{
	// 			return (this->_ptr < other._ptr);
	// 		}
	// };

	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		private:
			size_t		_size;
			size_t		_capacity;
			T			*_data = NULL;
			Allocator	_allocator;
			
			void	_checkOutOfBounds(int pos)
			{
				if(pos < 0 || pos >= static_cast<int>(this->_size))
					throw OutOfBoundsException(pos);
			}

			void	_reAlloc(size_t newCapacity)
			{
				T	*newBlock = this->_allocator.allocate(newCapacity);


				if(newCapacity < this->_size)
					this->_size = newCapacity;

				for(size_t i = 0; i < this->_size; i++)
					this->_allocator.construct(&newBlock[i], this->_data[i]);
				this->_allocator.deallocate(this->_data, this->_capacity);
				_data = newBlock;
				_capacity = newCapacity;
			}
		public:
		
			typedef ft::random_access_iterator<T>	iterator;
			// using ValueType = T;
			// using Iterator = VectorIterator<vector<T>>; //para usar apenas iterator no resto do código
			vector(void): _size(0), _capacity(2), _data(this->_allocator.allocate(this->_capacity))
			{
				//?começar com 0 igual o original ou já começar com algum espaço?
				_reAlloc(2);
			}
			vector(vector const&	instance): _size(instance._size), _capacity(instance._capacity), _data(this->_allocator.allocate(this->_capacity))
			{
				*this = instance;
			}
			~vector()
			{
				this->_allocator.deallocate(this->_data, this->_capacity);
			}

			vector&	operator=(const vector& other)
			{
				if (this->_capacity < other._size)
					this->_reAlloc(other._size);
				for(size_t i = 0; i < other._size; i++)
					this->_data[i] = other._data[i];
				return (*this);
			}

			T&	operator[](int pos)
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

			const T&	operator[](int pos) const
			{
				this->_checkOutOfBounds(pos);
				return (this->_data[pos]);
			}
			
			T&	at(int pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_data[pos]);
			}
			
			T&	front(void)
			{
				return (this->_data[0]);
			}
			
			T&	back(void)
			{
				return (this->_data[this->_size - 1]);
			}
			
			void push_back(const T&	value)
			{
				if(this->_size == this->_capacity)
					this->_reAlloc(this->_capacity * 2);
				this->_data[this->_size] = value;
				this->_size++;
			}

			void pop_back(void)
			{
				this->_data[this->_size - 1] = 0;
				this->_size--;
			}

			size_t size(void)
			{
				return (this->_size);
			}
			
			size_t capacity(void)
			{
				return (this->_capacity);
			}
			
			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			void assign(size_t count, const T& value)
			{
				if (this->_data)
					this->_allocator.deallocate(this->_data, this->_capacity);
				this->_size = count;
				this->_data = this->_allocator.allocate(this->_capacity);
				for(size_t i = 0; i < this->_size; i++)
					this->_data[i] = value;
			}

			// template< class InputIt >
			// void assign(InputIt first, InputIt last)
			// {
				
			// }

			void resize(size_t count, T value = T())
			{
				
			}

			//size_type max_size() const;
			size_t max_size(void) const
			{
				return (this->_allocator.max_size());
			}
			
			//allocator_type get_allocator() const;
			Allocator	get_allocator(void) const
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

