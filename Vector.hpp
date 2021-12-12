#include <iomanip>

namespace ft {

	template<class T, class Allocator = std::allocator<T> >
	class Vector
	{
		private:
			size_t	_size;
			size_t	_capacity;
			T		*_data = NULL;

			void _reAlloc(size_t newCapacity)
			{
				T	*newBlock = new T[newCapacity];

				if(newCapacity < _size)
					_size = newCapacity;

				for(size_t i = 0; i < _size; i++)
					newBlock[i] = _data[i];
				delete[] _data;
				_data = newBlock;
				_capacity = newCapacity;
			}
		public:
			Vector(void): _size(2), _capacity(2), _data(new T[this->_capacity])
			{
				//?começar com 0 igual o original ou já começar com algum espaço?
				_reAlloc(2);
				this->_data[0] = 0;
				this->_data[1] = 1;
			}
			Vector(Vector const &instance): _size(instance._size), _capacity(instance._capacity), _data(new T[this->_capacity])
			{
				*this = instance;
			}
			~Vector()
			{
				delete[] _data;
			}

			Vector &operator=(Vector const &right_hand_side)
			{
				if (this->_capacity < right_hand_side._size)
					this->_reAlloc(right_hand_side._size);
				for(size_t i = 0; i < right_hand_side._size; i++)
					this->_data[i] = right_hand_side._data[i];
				return (*this);
			}
		// operator= ok
		// assign ok
		// resize ok
		// get_allocator ??
		// at ok
		// operator[] ok
		// front ok
		// back ok
		// begin
		// end 
		// rbegin
		// rend
		// data
		// empty
		// size
		// max_size
		// reserve
		// capacity
		// shrink_to_fit
		// clear 
		// insert
		// erase
		// push_back
		// pop_back
		// swap
	};
}

