/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:11:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/12/17 21:17:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>

namespace ft {

	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		private:
			size_t	_size;
			size_t	_capacity;
			T		*_data = NULL;
			
			void	_checkOutOfBounds(int pos)
			{
				if(pos < 0 || pos >= static_cast<int>(this->_size))
					throw OutOfBoundsException(pos);
			}

			void	_reAlloc(size_t newCapacity)
			{
				T	*newBlock = new T[newCapacity];//!trocar news e deletes para allocators

				if(newCapacity < _size)
					_size = newCapacity;

				for(size_t i = 0; i < _size; i++)
					newBlock[i] = _data[i];
				delete[] _data;
				_data = newBlock;
				_capacity = newCapacity;
			}
		public:
			vector(void): _size(0), _capacity(2), _data(new T[this->_capacity])
			{
				//?começar com 0 igual o original ou já começar com algum espaço?
				_reAlloc(2);
			}
			vector(vector const&	instance): _size(instance._size), _capacity(instance._capacity), _data(new T[this->_capacity])
			{
				*this = instance;
			}
			~vector()
			{
				delete[] _data;
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
		// assign ok
		// resize ok
		// get_allocator ??
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
		// size
		// max_size
		// reserve
		//* capacity
		// shrink_to_fit
		// clear 
		// insert
		// erase
		//* push_back
		// pop_back
		// swap
	};
}

