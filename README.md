# ft_containers
C++ containers re-implementation | école 42

Some rules:

This project is about implementing the various container types of the C++ standard template library, coding in C++98, so any new feature of the containers MUST NOT be implemented, but every old feature (even deprecated) is expected. Member functions, Non-member and overloads are expected, and the implemented containers can bu up to 20 times slower compares to STL ones (tests are expected). Names must be respected. std::allocator must be used and the inner data structure for each container must be coherent (using a simple array for a map is not ok). iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented. For non-member overloads, the keyword `friend` is allowed. Each use of `friend` must be justified.

## Vector

>std::vector is a sequence container that encapsulates dynamic size arrays

Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.

The elements are stored contiguously, which means that elements can be accessed not only through iterators, but also using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an array.

in standart array the memory is allocated on the stack
in vectors, the data is heap allocated. Dynamic.

* Addition/removal of elements to the end of the array in constant time; that is, the time
needed to insert at the end is not dependent on the size of the array. 
* The time required for the insertion or removal of elements at the middle is directly
proportional to the number of elements behind the element being removed.
* The number of elements held is dynamic, and the vector class manages the
memory usage.

different forms of intantiating a vector in c++98:

```cpp
#include <vector>

int main ()
{
// vector of integers
//when you do not know how many integers you want to hold in it
std::vector<int> integers;

// Instantiate a vector with 10 elements (it can still grow)
std::vector<int> tenElements (10);

// Instantiate a vector with 10 elements, each initialized to 90
std::vector<int> tenElemInit (10, 90);

// Initialize vector to the contents of another
std::vector<int> copyVector (tenElemInit);

// Vector initialized to 5 elements from another using iterators
std::vector<int> partialCopy (tenElements.cbegin(),
tenElements.cbegin() + 5);

return 0;
}
```
Insertion in a vector happens at the end of the array, and elements are “pushed” into its back using the member function `push_back()`

**insert()**

```cpp
// insert an element at the beginning
integers.insert (integers.begin (), 25);

// Insert 2 elements of value 45 at the end
integers.insert (integers.end (), 2, 45);

// Another vector containing 2 elements of value 30
vector <int> another (2, 30);

// Insert two elements from another container in position [1]
integers.insert (integers.begin () + 1, another.begin (), another.end ());

```

`insert()` is an inefficient way to add elements to the vector because adding elements in the beginning or the middle makes the vector class shift all subsequent elements backward

`at(2)` == `[2]` but `at()` performs a runtime check against the `size()` of the container and throws an exception if you cross the boundaries

>If your container needs to have very frequent insertions in the middle, you should ideally choose the std::list

*move vs copy*

### Allocators

Allocators are used by the C++ Standard Library to handle the allocation and deallocation of elements stored in containers. All C++ Standard Library containers except std::array have a template parameter of type allocator<Type>, where Type represents the type of the container element. 

* [cpp reference - vector](https://en.cppreference.com/w/cpp/container/vector)
* [VECTOR/DYNAMIC ARRAY - Making DATA STRUCTURES in C++](https://www.youtube.com/watch?v=ryRf4Jh_YC0)

**Size and Capacity**

The size of a vector is the number of elements stored in a vector. The capacity of a vector is the total number of elements that can potentially be stored in the vector before it reallocates memory to accommodate more elements.

**reallocation**

The implementation of the reallocation logic is smart—to avoid another reallocation on insertion of another element, it preemptively allocates a capacity greater than the requirements of the immediate scenario.

> The preemptive increase in the capacity of the vector when the internal buffer is reallocated is not regulated by any clause in the C++ standard. This level of performance optimization may vary depending on the provider of STL library in use.
