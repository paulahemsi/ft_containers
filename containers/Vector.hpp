/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:11:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/02/21 22:04:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "type_traits.hpp"
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
			pointer		_element;
			
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
					this->_allocator.construct(&newBlock[i], this->_element[i]);
				this->_allocator.deallocate(this->_element, this->_capacity);
				_element = newBlock;
				_capacity = newCapacity;
			}
		public:
			//empty container constructor (default constructor)
			//Constructs an empty container, with no elements.
			explicit vector (const allocator_type& alloc = allocator_type()):
																			_size(0),
																			_capacity(0),
																			_allocator(alloc),
																			_element(NULL) {}
			//fill constructor
			//Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
																																_size(n),
																																_capacity(n),
																																_allocator(alloc),
																																_element(this->_allocator.allocate(this->_capacity))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_element[i], val);
			}
			//range constructor
			//Constructs a container with as many elements as the range [first,last], with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 666):
																											_size(last - first),
																											_capacity(last - first),
																											_allocator(alloc),
																											_element(this->_allocator.allocate(this->_size))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_element[i], *(first + i));
			}
			//copy constructor
			//Constructs a container with a copy of each of the elements in other, in the same order
			vector(const vector&	other):
											_size(other._size),
											_capacity(other._capacity),
											_element(this->_allocator.allocate(this->_capacity))
			{
				*this = other;
			}
			~vector()
			{
				this->_allocator.deallocate(this->_element, this->_capacity);
			}

			vector&	operator=(const vector& other)
			{
				if (this->_capacity < other._size)
					this->_reAlloc(other._size);
				for(size_type i = 0; i < other._size; i++)
					this->_allocator.construct(&this->_element[i], other._element[i]);
				return (*this);
			}

			reference	operator[](int pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_element[pos]);
			}

			iterator begin(void)
			{
				return iterator(this->_element);
			}

			iterator end(void)
			{
				return iterator(this->_element + this->_size);
			}

			const_iterator begin(void) const
			{
				return const_iterator(this->_element);
			}

			const_iterator end(void) const
			{
				return const_iterator(this->_element + this->_size);
			}

			reverse_iterator rbegin(void)
			{
				return reverse_iterator(this->end() - 1);
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(this->begin() - 1);
			}

			const_reverse_iterator rbegin(void) const
			{
				return const_reverse_iterator(this->end() - 1);
			}

			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(this->begin()  - 1);
			}

			const reference	operator[](int pos) const
			{
				this->_checkOutOfBounds(pos);
				return (this->_element[pos]);
			}

			reference	at(int pos)
			{
				this->_checkOutOfBounds(pos);
				return (this->_element[pos]);
			}

			reference	front(void)
			{
				return (this->_element[0]);
			}

			reference	back(void)
			{
				return (this->_element[this->_size - 1]);
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
				this->_allocator.construct(&this->_element[this->_size], value);
				this->_size++;
			}

			void pop_back(void)
			{
				this->_element[this->_size - 1] = 0;
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

			//Replaces the contents with count copies of value value
			void assign(size_type count, const value_type& value)
			{
				if (this->_element)
					this->_allocator.deallocate(this->_element, this->_capacity);
				this->_size = count;
				if (this->_capacity < this->_size)
					this->_capacity = this->_size;
				this->_element = this->_allocator.allocate(this->_capacity);
				for(size_type i = 0; i < this->_size; i++)
					this->_element[i] = value;
			}

			// Replaces the contents with copies of those in the range (first, last). The behavior is undefined if either argument is an iterator into *this.
			template< class InputIt >
			void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = false)
			{
				if (this->_element)
					this->_allocator.deallocate(this->_element, this->_capacity);
				this->_size = last - first;
				if (this->_capacity < this->_size)
					this->_capacity = this->_size;
				this->_element = this->_allocator.allocate(this->_capacity);
				for(size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_element[i], *(first + i));
			}

			//size_type max_size() const;
			size_type max_size(void) const
			{
				return (this->_allocator.max_size());
			}

			//Returns pointer to the underlying array serving as element storage. The pointer is such that range [data(); data() + size()) is always a valid range, even if the container is empty (data() is not dereferenceable in that case).
			T* data() {return (this->_element);}

			const T* data() const {return (this->_element);}

			//Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
			void clear(void)
			{
				this->_allocator.destroy(this->_element);
				this->_size = 0;
			}

			//Removes from the vector either a single element (position) or a range of elements ([first,last)) This effectively reduces the container size by the number of elements removed, which are destroyed.
			iterator erase(iterator position)
			{
				for(size_type i = 0; (position + i + 1) != this->end(); i++)
					this->_allocator.construct(&(*(position + i)), *(position + i + 1));
				this->_size--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				for(int i = 0; (last + i) != this->end(); i++)
					this->_allocator.construct(&(*(first + i)), *(last + i));
				this->_size -= last - first;
				return(first);
			}

			//Requests that the vector capacity be at least enough to contain n elements.
			void reserve(size_type n)
			{
				if (this->_capacity < n)
					this->_reAlloc(n);
			}

			//Returns a copy of the allocator object associated with the vector.
			allocator_type get_allocator() const { return (this->_allocator); }

			//!Dá diferença pro workspace
			//Resizes the container so that it contains n elements.
			//If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
			//If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
			//If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
			void resize (size_type n, value_type val = value_type())
			{
				if(n < this->_size)
				{
					for(size_type i = n; i <= this->_size; i++)
						this->_allocator.destroy(&this->_element[i]);
					this->_size = n;
				}
				else if (n > this->_size)
				{
					if (n > this->_capacity)
						this->_reAlloc(n);
					for(size_type i = this->_size; i < n; i++)
						this->_allocator.construct(&this->_element[i], val);
					this->_size = n;
				}
			}

			//The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted. The parameters determine how many elements are inserted and to which values they are initialized.

			//single element
			iterator insert(iterator position, const value_type& val)
			{
				size_type index_to_insert = position - this->begin();

				if((this->_size + 1) > this->_capacity)
					this->_reAlloc(this->_size + 1);
				for(size_t i = this->_size; i > index_to_insert; i--)
					this->_allocator.construct(&this->_element[i], this->_element[i - 1]);
				this->_allocator.construct(&this->_element[index_to_insert], val);
				this->_size++;
				return (this->begin() + index_to_insert);
			}
			//fill
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type index_to_insert = position - this->begin();
				if((this->_size + n) > this->_capacity)
					this->_reAlloc(this->_size + n);
				for(size_type i = this->_size + n - 1, j = 1; i >= (index_to_insert + n); i--, j++)
					this->_allocator.construct(&this->_element[i], this->_element[this->_size - j]);
				for(size_type i = 0; i < n; i++)
					this->_allocator.construct(&this->_element[index_to_insert + i], val);
				this->_size += n;
			}
			//range
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 666)
			{
				size_type index_to_insert = position - this->begin();
				size_type quantity_to_insert = last - first;
				if((this->_size + quantity_to_insert) > this->_capacity)
					this->_reAlloc(this->_size + quantity_to_insert);
				for(size_type i = this->_size + quantity_to_insert - 1, j = 1; i >= (index_to_insert + quantity_to_insert); i--, j++)
					this->_allocator.construct(&this->_element[i], this->_element[this->_size - j]);
				for(size_type i = 0; i < quantity_to_insert; i++)
					this->_allocator.construct(&this->_element[index_to_insert + i], *(first + i));
				this->_size += quantity_to_insert;
			}

			//Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements. All iterators and references remain valid. The past-the-end iterator is invalidated.
			void swap(vector& other)
			{
				size_type	temp_size = other._size;
				size_type	temp_capacity = other._capacity;
				Alloc		temp_allocator = other._allocator;
				pointer		temp_element = other._element;

				other._size = this->_size;
				other._capacity = this->_capacity;
				other._allocator = this->_allocator;
				other._element = this->_element;

				this->_size = temp_size;
				this->_capacity = temp_capacity;
				this->_allocator = temp_allocator;
				this->_element = temp_element;
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
	};

	//Specializes the std::swap algorithm for std::vector. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs)
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

	//The equality comparison (operator==) is performed by first comparing sizes, and if they match, the elements are compared sequentially using operator==, stopping at the first mismatch (as if using algorithm equal)
	template <class T, class Alloc>
	bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
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
