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

Allocators are classes that define memory models to be used by some parts of the Standard Library, and most specifically, by STL containers.

Allocators are used by the C++ Standard Library to handle the allocation and deallocation of elements stored in containers. All C++ Standard Library containers except std::array have a template parameter of type allocator<Type>, where Type represents the type of the container element. 

> Allocators represent a special memory model and are an abstraction used to translate the need to use memory into a raw call for memory. They provide an interface to allocate, create, destroy, and deallocate objects. With allocators, containers and algorithms can be parameterized by the way the elements are stored. For example, you could implement allocators that use shared memory or that map the elements to a persistent database

With allocators, containers and algorithms can be parameterized by the way the elements are stored.

As mentioned, allocate and deallocate are simply low level memory management and do not play a part in object construction and destruction. This would mean that the default usage of the keywords new and delete would not apply in these functions

the following code:

```c++
A* a = new A;
delete a;
```

is actually interpreted by the compiler as:

```c++
// assuming new throws std::bad_alloc upon failure
A* a = ::operator new(sizeof(A)); 
a->A::A();
if ( a != 0 ) {  // a check is necessary for delete
    a->~A();
    ::operator delete(a);
}
```

The purpose of the allocator is to 2allocate raw memory without construction of objects, as well as simply deallocate memory without the need to destroy them, hence the usage of operator new and operator delete directly is preferred over the usage of the keywords new and delete.

Following these are helper functions to do copy construction (construct(p, t)) and destroy (destroy(p)) an object, as well as getting the largest value that can meaningfully be passed to allocate (max_size), copy constructor and default constructor, and the equality checking operators(== and !=).

A sample allocator:

```cpp
template<typename T>
class Allocator {
public : 
    //    typedefs
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

public : 
    //    convert an allocator<T> to allocator<U>
    template<typename U>
    struct rebind {
        typedef Allocator<U> other;
    };

public : 
    inline explicit Allocator() {}
    inline ~Allocator() {}
    inline explicit Allocator(Allocator const&) {}
    template<typename U>
    inline explicit Allocator(Allocator<U> const&) {}

    //    address
    inline pointer address(reference r) { return &r; }
    inline const_pointer address(const_reference r) { return &r; }

    //    memory allocation
    inline pointer allocate(size_type cnt, 
       typename std::allocator<void>::const_pointer = 0) { 
      return reinterpret_cast<pointer>(::operator new(cnt * sizeof (T))); 
    }
    inline void deallocate(pointer p, size_type) { 
        ::operator delete(p); 
    }

    //    size
    inline size_type max_size() const { 
        return std::numeric_limits<size_type>::max() / sizeof(T);
 }

    //    construction/destruction
    inline void construct(pointer p, const T& t) { new(p) T(t); }
    inline void destroy(pointer p) { p->~T(); }

    inline bool operator==(Allocator const&) { return true; }
    inline bool operator!=(Allocator const& a) { return !operator==(a); }
};    //    end of class Allocator 
```

* [C-Standard-Allocator-An-Introduction-and-Implement](https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement)

### Size and Capacity

The size of a vector is the number of elements stored in a vector. The capacity of a vector is the total number of elements that can potentially be stored in the vector before it reallocates memory to accommodate more elements.

### reallocation

The implementation of the reallocation logic is smart—to avoid another reallocation on insertion of another element, it preemptively allocates a capacity greater than the requirements of the immediate scenario.

> The preemptive increase in the capacity of the vector when the internal buffer is reallocated is not regulated by any clause in the C++ standard. This level of performance optimization may vary depending on the provider of STL library in use.

## Vector in C++98 :

| Member Type | Definition |
|------------------|------------|
| value_type | T |
|allocator_type | Allocator |
|size_type | Unsigned integer type (usually std::size_t)|
|difference_type | Signed integer type (usually std::ptrdiff_t)|
|reference | value_type&|
|const_reference |const value_type&|
|pointer | Allocator::pointer|
|const_pointer | Allocator::const_pointer|
|iterator | [LegacyRandomAccessIterator](https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator) and [LegacyContiguousIterator](https://en.cppreference.com/w/cpp/named_req/ContiguousIterator) to value_type|
|const_iterator | [LegacyRandomAccessIterator](https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator) and [LegacyContiguousIterator](https://en.cppreference.com/w/cpp/named_req/ContiguousIterator) to const|
|reverse_iterator | std::reverse_iterator<iterator>|
|const_reverse_iterator | std::reverse_iterator<const_iterator>|




| Public Member Functions | |
|------------------|------------|
| *constructor* | |
| *destructor* | |
| *operator=*        |assigns values to the container|
| *assign*           |assigns values to the container|
| *get_allocator*    |returns the associated allocator|
| **Element access:**|  |
| *at* | access specified element with bounds checking|
|*operator[]*|	access specified element|
|*front* | access the first element |
|*back* | access the last element |
|*data* | direct access to the underlying array |
| **Iterators:**|  |
| *begin* | returns an iterator to the beginning |
| *end* | returns an iterator to the end |
| *rbegin* | returns a reverse iterator to the beginning |
| *rend* | returns a reverse iterator to the end |
| **Capacity:**|  |
| *empty* | checks whether the container is empty |
| *size* | returns the number of elements |
| *max_size* | returns the maximum possible number of elements |
| *reserve* | reserves storage |
| *capacity* | returns the number of elements that can be held in currently allocated storage |
| **Modifiers:**|  |
| *clear* | clears the contents |
| *insert* | inserts elements |
| *erase* | erases elements |
| *push_back* | adds an element to the end |
| *pop_back* | removes the last element |
| *resize* | changes the number of elements stored |
| *swap* | swaps the contents |


|Non-Member Functions||
|-------------------|--------|
|(function templates)||
|*operator==* | lexicographically compares the values in the vector |
|*operator!=* | lexicographically compares the values in the vector |
|*operator<* | lexicographically compares the values in the vector |
|*operator<=* | lexicographically compares the values in the vector |
|*operator>* | lexicographically compares the values in the vector |
|*operator>=* | lexicographically compares the values in the vector |
|*std::swap(std::vector)*| specializes the std::swap algorithm |

|Constructors | |
|-------------|---|
|*vector();*    |Default constructor. Constructs an empty container with a default-constructed allocator.|
|*explicit vector( const Allocator& alloc );*|Constructs an empty container with the given allocator alloc|
|*explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());*| Constructs the container with count copies of elements with value value|
|*template< class InputIt > vector( InputIt first, InputIt last,const Allocator& alloc = Allocator() );*|Constructs the container with the contents of the range (first, last)*|
|*vector( const vector& other );*|Copy constructor. Constructs the container with the copy of the contents of other.|

**Parameters**
*alloc* - allocator to use for all memory allocations of this container
*count* - the size of the container
*value* - the value to initialize elements of the container with
*first*, *last* - the range to copy the elements from
*other* - another container to be used as source to initialize the elements of the container with
*init* - initializer list to initialize the elements of the container with

Calls to `Allocator::allocate` may throw exceptions

*This constructor has the same effect as vector(static_cast<size_type>(first), static_cast<value_type>(last), a) if InputIt is an integral type.

[cpp reference constructors](https://en.cppreference.com/w/cpp/container/vector/vector)


## Friend

Subject: *For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.*

[from Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-170)

A `friend function` is a function that is **not** a member of a class but **has access to the class's private and protected members**. Friend functions are not considered class members; they are normal external functions that are given special access privileges. Friends are not in the class's scope, and they are not called using the member-selection operators (. and ->) unless they are members of another class. A friend function is declared by the class that is granting access. The friend declaration can be placed anywhere in the class declaration. It is not affected by the access control keywords.

```c++
#include <iostream>

using namespace std;
class Point
{
    friend void ChangePrivate( Point & );
public:
    Point( void ) : m_i(0) {}
    void PrintPrivate( void ){cout << m_i << endl; }

private:
    int m_i;
};

void ChangePrivate ( Point &i ) { i.m_i++; }

int main()
{
   Point sPoint;
   sPoint.PrintPrivate();
   ChangePrivate(sPoint);
   sPoint.PrintPrivate();
}
```

Class member functions can be declared as `friends` in other classes

```c++
class B;

class A {
public:
   int Func1( B& b );

private:
   int Func2( B& b );
};

class B {
private:
   int _b;

   // A::Func1 is a friend function to class B
   // so A::Func1 has access to all members of B
   friend int A::Func1( B& );
};

int A::Func1( B& b ) { return b._b; }   // OK
int A::Func2( B& b ) { return b._b; }   // C2248
```

Last but not least, A `friend class` is a class all of whose member functions are friend functions of a class, that is, whose member functions have access to the other class's private and protected members.

```cpp
#include <iostream>

using namespace std;
class YourClass {
friend class YourOtherClass;  // Declare a friend class
public:
   YourClass() : topSecret(0){}
   void printMember() { cout << topSecret << endl; }
private:
   int topSecret;
};

class YourOtherClass {
public:
   void change( YourClass& yc, int x ){yc.topSecret = x;}
};

int main() {
   YourClass yc1;
   YourOtherClass yoc1;
   yc1.printMember();
   yoc1.change( yc1, 5 );
   yc1.printMember();
}
```

Friendship is not mutual unless explicitly specified as such.
Friendship is not inherited.
Friendship is not transitive, so classes that are friends of YourOtherClass cannot access YourClass's private members.

## Iterators

### Iterators traits

std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types. This makes it possible to implement algorithms only in terms of iterators.

The template can be specialized for user-defined iterators so that the information about the iterator can be retrieved even if the type does not provide the usual typedefs.

[stackOverflow usefull thread](https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait)

### Random-access and Bidirectional iterators

**Random-access iterators** are iterators that can be used to access elements at an arbitrary offset position relative to the element they point to, offering the same functionality as pointers. Random-access iterators are the most complete iterators in terms of functionality. All pointer types are also valid random-access iterators.

**Bidirectional iterators** are iterators that can be used to access the sequence of elements in a range in both directions (towards the end and towards the beginning). They are similar to forward iterators, except that they can move in the backward direction also, unlike the forward iterators, which can move only in the forward direction.

It is to be noted that containers like vector, deque support random-access iterators. This means that if we declare normal iterators for them, and then those will be [random-access iterators](https://www.geeksforgeeks.org/random-access-iterators-in-cpp/), just like in case of list, map, multimap, set and multiset they are [bidirectional iterators](https://www.geeksforgeeks.org/bidirectional-iterators-in-cpp/).


| Feature | random access iterator | bidirectional iterator |
|---------|------------------------|------------------------|
|can be used in multi-pass algorithms, i.e., algorithm which involves processing the container several times in various passes. |:heavy_check_mark:|:heavy_check_mark:|
|can be compared for equality with another iterator. Since, iterators point to some location, so the two iterators will be equal only when they point to the same position, otherwise not.|:heavy_check_mark:|:heavy_check_mark:|
|can be dereferenced both as a rvalue as well as a lvalue.|:heavy_check_mark:|:heavy_check_mark:|
|can be incremented and decremented, so that it refers to the next/previous element in sequence, using operator ++() or --()|:heavy_check_mark:|:heavy_check_mark:|
|support all relational operators (`==` `>=` `<=` `!=`)|:heavy_check_mark:|:x: (only `==`)|
|can be used with arithmetic operators like +, – and so on. This means that Random-access iterators can move in both the direction, and that too randomly|:heavy_check_mark:|:x:|
|support offset dereference operator ([ ]), which is used for random-access|:heavy_check_mark:|:x:|
|The value pointed to by these iterators can be exchanged or swapped|:heavy_check_mark:|:heavy_check_mark:|

* [cpp reference - vector](https://en.cppreference.com/w/cpp/container/vector)
* [VECTOR/DYNAMIC ARRAY - Making DATA STRUCTURES in C++](https://www.youtube.com/watch?v=ryRf4Jh_YC0)
