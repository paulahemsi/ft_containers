# ft_containers

[Wiki](https://github.com/paulahemsi/ft_containers/wiki)

C++ containers re-implementation | école 42

# Intro

This project is about implementing the various container types of the C++ standard template library, coding in C++98

![image](https://user-images.githubusercontent.com/63563271/164947012-ab2370d6-06a2-4fd5-92ef-e8c2f320fab3.png)



Some rules:

Any new feature of the containers MUST NOT be implemented, but every old feature (even deprecated) is expected. Member functions, Non-member and overloads are expected, and the implemented containers can bu up to 20 times slower compares to STL ones (tests are expected). 

`std::allocator` must be used and the inner data structure for each container must be coherent (using a simple array for a map is not ok). `iterators_traits`, `reverse_iterator`, `enable_if`, `is_integral`, `equal/lexicographical compare`, `std::pair`, `std::make_pair`, must be reimplemented. 

For non-member overloads, the keyword `friend` is allowed. Each use of `friend` must be justified.

## Usage

```bash
git clone git@github.com:paulahemsi/ft_containers.git
cd ft_containers

make #compile all ft::<container> versions
make <container>_script #execute tests with ft::<container> and std::<container> (compare outputs and time)
./tests/<container>/ft.out #ft::<container> test output
./tests/<container>/original #std::<container> test output
make test #execute all containers tests

```


## folder-structure


    ├── aux_templates  		#lexicographical compare, pair and type_traits
    │    
    ├── containers   		#vector, map, set and stack
    │   
    ├── iterators			#random access, biderectional, reverse and traits
    │   
    ├── rb_tree			#red-black tree
    │   ├── includes    
    │   └── tests         
    │          
    └── tests        		#containers tests
 		├── auxiliary         
    	├── intra
    	├── map         
    	├── mk      		#makefile includes
    	├── set        
    	├── stack
    	└── vector



* [Vector](#Vector)
    * [Allocators](#Allocators)
    * [Size_and_Capacity](#Size_and_Capacity)
    * [Reallocation](#Reallocation)
    * [Vector in C++98](#Vector_in_C++98)
* [Friend keyword](#Friend_keyword)
* [Explicit keyword](#Explicit_keyword)
* [Iterators](#Iterators)
    * [Iterators traits](#Iterators_traits)
    * [Random access and Bidirectional iterators](#Random-access_and_Bidirectional_iterators)
    * [Reverse iterators](#Reverse_iterators)
* [Type_traits](#Type_traits)
    * [enable_if](#enable_if)
    * [is_integral](#is_integral)
* [Clock](#clock)
* [Map](#Map)
    * [Map in C++98](#Map_in_C++98)
    * [std::pair C++98](#std::pair_C++98)
* [Red-black tree](#Red-black_tree)
    * [Sentinel node](#Sentinel_node)
* [Value type C++98](#Value_type_C++98)
* [Allocator Rebind](#Allocator_Rebind)

# Vector

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


* [cpp reference - vector](https://en.cppreference.com/w/cpp/container/vector)
* [VECTOR/DYNAMIC ARRAY - Making DATA STRUCTURES in C++](https://www.youtube.com/watch?v=ryRf4Jh_YC0)

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

## Allocators

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

## Size_and_Capacity

The size of a vector is the number of elements stored in a vector. The capacity of a vector is the total number of elements that can potentially be stored in the vector before it reallocates memory to accommodate more elements.

## Reallocation

The implementation of the reallocation logic is smart—to avoid another reallocation on insertion of another element, it preemptively allocates a capacity greater than the requirements of the immediate scenario.

> The preemptive increase in the capacity of the vector when the internal buffer is reallocated is not regulated by any clause in the C++ standard. This level of performance optimization may vary depending on the provider of STL library in use.

## Vector_in_C++98

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


# Friend_keyword

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

# Explicit_keyword

from [this stackOverflow thread](https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean)

The compiler is allowed to make one implicit conversion to resolve the parameters to a function. What this means is that the compiler can use constructors callable with a single parameter to convert from one type to another in order to get the right type for a parameter.

Here's an example class with a constructor that can be used for implicit conversions:

```cpp
class Foo
{
public:
  // single parameter constructor, can be used as an implicit conversion
  Foo (int foo) : m_foo (foo) 
  {
  }

  int GetFoo () { return m_foo; }

private:
  int m_foo;
};
```

Here's a simple function that takes a `Foo` object:

```cpp
void DoBar (Foo foo)
{
  int i = foo.GetFoo ();
}
```

and here's where the `DoBar` function is called:

```cpp
int main ()
{
  DoBar (42);
}
```

The argument is not a `Foo` object, but an `int`. However, there exists a constructor for `Foo` that takes an `int` so this constructor can be used to convert the parameter to the correct type.

The compiler is allowed to do this once for each parameter.

Prefixing the `explicit` keyword to the constructor prevents the compiler from using that constructor for implicit conversions. Adding it to the above class will create a compiler error at the function call `DoBar (42)`. It is now necessary to call for conversion explicitly with `DoBar (Foo (42))`

The reason you might want to do this is to avoid accidental construction that can hide bugs.
Contrived example:

Suppose, you have a class `String`:

```cpp
class String {
public:
    String(int n); // allocate n bytes to the String object
    String(const char *p); // initializes object with char *p
};
```

Now, if you try:

```cpp
String mystring = 'x';
```

The character `'x'` will be **implicitly** converted to `int` and then the `String(int)` constructor will be called. But, this is not what the user might have intended. So, to prevent such conditions, we shall define the constructor as `explicit`:

```cpp
class String {
public:
    explicit String (int n); //allocate n bytes
    String(const char *p); // initialize sobject with string p
};
```

# Iterators

[Iterator source code](https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#_ZNSt16reverse_iteratorpLENSt15iterator_traitsIT_E15difference_typeE)
	
## Iterators_traits

std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types. This makes it possible to implement algorithms only in terms of iterators.

The template can be specialized for user-defined iterators so that the information about the iterator can be retrieved even if the type does not provide the usual typedefs.

> the point is to make do_something work with pointers as well as class based iterators

[stackOverflow usefull thread](https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait)

## Random-access_and_Bidirectional_iterators

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


## Reverse_iterators

[std::reverse_iterator](https://en.cppreference.com/w/cpp/iterator/reverse_iterator) is an iterator adaptor that reverses the direction of a given iterator.

 In other words, when provided with (at least) a `bidirectional iterator`, `std::reverse_iterator` produces a **new iterator** that moves **from the end to the beginning** of the sequence defined by the *underlying bidirectional iterator*.
 
 For a reverse iterator r constructed from an iterator i, the relationship `&*r == &*(i-1)` is always true (as long as r is dereferenceable); thus a reverse iterator constructed from a one-past-the-end iterator dereferences to the last element in a sequence.

![image](https://user-images.githubusercontent.com/63563271/148653829-be8b822c-e152-451d-bef4-9e242c81da20.png) 
![image](https://user-images.githubusercontent.com/63563271/151715136-dc6932c1-9947-4a3e-9dd0-4f04985ec786.png)

* [Tricky Reverse Iterator](https://www.youtube.com/watch?v=V89gtNl4pZM)

# Type_traits

[Header](https://www.cplusplus.com/reference/type_traits/) from C++11 that defines a series of classes to obtain type information on compile-time.

[type_traits source code](https://code.woboq.org/gcc/libstdc++-v3/include/std/type_traits.html)

## enable_if

Enable type if condition is met
The type T is enabled as member type `enable_if::type` if `Cond` is **true**.

Otherwise, `enable_if::type` is not defined.

This is useful to hide signatures on compile time when a particular condition is not met, since in this case, the member `enable_if::type` will not be defined and attempting to compile using it should fail.

For eg. those two vector constructors are very distincts: besides the allocator, one is suposed to receive Iterators, the other a size_t and the vector type:

```cpp
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
				_size(n),
				_capacity(n),
				_allocator(alloc),
				_data(this->_allocator.allocate(this->_capacity))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i], val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
				_size(last - first),
				_capacity(last - first),
				_allocator(alloc),
				_data(this->_allocator.allocate(this->_size))
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i], *(first + i));
			}
```

But as the second one is a template, this initialization:

```cpp
ft::vector<int> tenElement90(10, 90);
```

will call the second contructor, and as the arguments are integers and not iterators, we have a compiler error.

To avoid those kind of situations, [enable_if](https://www.cplusplus.com/reference/type_traits/enable_if/) must be implemented, adding an extra condition to the second constructor saying *"not call this if the type being passed are an integral type"*

## is_integral

[is_integral](https://www.cplusplus.com/reference/type_traits/is_integral/) is the other piece needed to the condicion above.

Trait class that identifies whether T is an integral type.

```cpp
// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int main() {

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}
```

```
i is odd: true
i is even: false
```

# Clock

[from cplusplus reference](https://www.cplusplus.com/reference/ctime/clock/)

`clock_t clock (void)`

Returns the processor time consumed by the program.

The value returned is expressed in clock ticks, which are units of time of a constant but system-specific length (with a relation of CLOCKS_PER_SEC clock ticks per second).

The epoch used as reference by clock varies between systems, but it is related to the program execution (generally its launch). To calculate the actual processing time of a program, the value returned by clock shall be compared to a value returned by a previous call to the same function.

**Return Value**:

The number of clock ticks elapsed since an epoch related to the particular program execution.

On failure, the function returns a value of -1.

clock_t is a type defined in <ctime> as an alias of a fundamental arithmetic type.

# Map

```c++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map;
```

std::map is a **sorted associative container** that contains key-value pairs with unique keys. Keys are sorted by using the comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. Maps are usually implemented as *red-black trees*.

> Everywhere the standard library uses the Compare requirements, uniqueness is determined by using the equivalence relation. In imprecise terms, two objects a and b are considered equivalent (not unique) if neither compares less than the other: !comp(a, b) && !comp(b, a).

## Map_in_C++98

| Member Type | Definition |
|------------------|------------|
|*key_type* | The first template parameter (Key) |
|*mapped_type* | The second template parameter (T) |
|*value_type*| pair<const key_type,mapped_type>|
|*key_compare* | The third template parameter (Compare)|
|*allocator_type* |The fourth template parameter (Alloc)|
|*reference* | allocator_type::reference|
|*const_reference* | allocator_type::const_reference|
|*pointer* | allocator_type::pointer|
|*const_pointer* | allocator_type::const_pointer|
|*iterator* | a bidirectional iterator to value_type|
|*const_iterator*	| a bidirectional iterator to const value_type|
|*reverse_iterator* | reverse_iterator<iterator>|
|*const_reverse_iterator* | reverse_iterator<const_iterator>|
|*difference_type* | a signed integral type, identical to: iterator_traits<iterator>::difference_type|
|*size_type* | an unsigned integral type that can represent any non-negative value of difference_type|

| Member Classes | Definition |
|------------------|------------|
|value_compare | Nested function class to comapre objects of type value_type|

| Public Member Functions | |
|------------------|------------|
| *constructor* | |
| *destructor* | |
| *operator=*        |Copy container content|
| **Iterators:**|  |
| *begin* | returns an iterator to the beginning |
| *end* | returns an iterator to the end |
| *rbegin* | returns a reverse iterator to the beginning |
| *rend* | returns a reverse iterator to the end |
| **Capacity:**|  |
| *empty* | checks whether the container is empty |
| *size* | return container size |
| *max_size* | return maximum size |
| **Element access:**|  |
|*operator[]*|	access element|
| **Modifiers:**|  |
| *insert* | insert elements |
| *erase* | erase elements |
| *swap* | swaps content |
| *clear* | clears content |
| **Observers:**|  |
| *key_comp* |Return key comparison object|
|*value_comp*|Return value comparison object|
| **Operations:**|  |
|*find*|Get iterator to element|
|*count*|Count elements with a specific key|
|*lower_bound*|Return iterator to lower bound|
|*upper_bound*|Return iterator to upper bound|
|*equal_range*|Get range of equal elements|
| **Allocator:** | |
|*get_allocator* | Get allocator|

## std::pair_C++98

```cpp
template <class T1, class T2> struct pair;
```

This class couples together a pair of values, which may be of different types (T1 and T2). The individual values can be accessed through its public members first and second.

Pairs are a particular case of [tuple](https://www.cplusplus.com/reference/tuple/tuple/)(C++11).

| Member types| Definition|
|------------------|------------|
|*first_type* |The first template parameter (T1)|
|*second_type* |The second template parameter (T2)|

| Member variable| Definition|
|------------------|------------|
|*first* |The first value in the pair|
|*second* |The second value in the pair|

| Public Member Functions | |
|------------------|------------|
| *(constructor)* | Construct pair |
| *pair::operator=* | Assign content |
| *pair::swap* | Swap content |

|Non-member function overloads | |
|------------------|------------|
|*relational operators*|Relational operators for pair (function template)|

# Red-black_tree

[From Wikipedia](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)

In computer science, a red–black tree is a kind of [self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree). Each node stores an extra bit representing "color" ("red" or "black"), used to ensure that the tree remains balanced during insertions and deletions

When the tree is modified, the new tree is rearranged and "repainted" to restore the coloring properties that constrain how unbalanced the tree can become in the worst case. The properties are designed such that this rearranging and recoloring can be performed efficiently.

The `black depth` of a node is defined as the number of black nodes **from the root to that node** (i.e. the number of black ancestors). The `black height` of a red–black tree is the number of black nodes **in any path from the root to the leaves**, which, by requirement 4, is **constant** (alternatively, it could be defined as the black depth of any leaf node).

In addition to the **requirements** imposed on a binary search tree the following **must be satisfied** by a red–black tree:

* Each node is either red or black.
* All NIL nodes (figure 1) are considered black.
* A red node does not have a red child.
* Every path from a given node to any of its descendant NIL nodes goes through the same number of black nodes.

The `read-only operations`, such as search or tree traversal, **do not** affect any of the requirements. On the other hand, the `modifying operations` **insert** and **delete** easily maintain requirements 1 and 2, but with respect to the other requirements some *extra effort has to be taken*, in order to avoid the introduction of a violation of requirement 3, called a `red-violation`, or of requirement 4, called a `black-violation`.

The requirements enforce a critical property of red–black trees: **the path from the root to the farthest leaf is no more than twice as long as the path from the root to the nearest leaf**. The result is that the tree is `height-balanced`. Since operations such as `inserting`, `deleting`, and `finding` values require worst-case time proportional to the height of the tree, this upper bound on the height allows red–black trees to be efficient in the worst case, namely logarithmic in the number n of entries, which is not the case for ordinary binary search trees.

[Red-black three visualization](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)

![red-black-tree](https://user-images.githubusercontent.com/63563271/156001637-d9b2a4da-0431-44f7-be29-a4ad14a7c5b7.gif)

## Sentinel_node

In order to save a marginal amount of execution time, these (possibly many) NIL leaves may be implemented as pointers to one unique (and black) sentinel node

The globally available pointer sentinel to the single deliberately prepared data structure Sentinel = *sentinel is used to indicate the absence of a child, instead of lots of null pointers

```cpp
// global variable
bst_node Sentinel, *sentinel = &Sentinel;
// global initialization
Sentinel.child[0] = Sentinel.child[1] = sentinel;

BST->root = sentinel;                 // before the first insertion (not shown)
```

Note that the pointer sentinel has always to represent every leaf of the tree. This has to be maintained by the insert and delete functions. It is, however, about the same effort as when using a NULL pointer.

```cpp
struct bst_node *SearchWithSentinelnode(struct bst *bst, int search_key) {
    struct bst_node *node;
    // Prepare the “node” Sentinel for the search:
    sentinel->key = search_key;
 
    for (node = bst->root;;) {
        if (search_key == node->key)
            break;
        if search_key < node->key:
            node = node->child[0];    // go left
        else
            node = node->child[1];    // go right
    }
 
    // Post-processing:
    if (node != sentinel)
        return node;                  // found
    // search_key is not contained in the tree:
    return NULL;
}
```

* With the use of SearchWithSentinelnode searching loses the R/O property. This means that in applications with concurrency it has to be protected by a mutex, an effort which normally exceeds the savings of the sentinel.
* SearchWithSentinelnode does not support the tolerance of duplicates.
* There has to be exactly one “node” to be used as sentinel, but there may be extremely many pointers to it.

# Value_type_C++98

```cpp
std::map<Key,T,Compare,Allocator>::value_compare
```
```cpp
class value_compare;
```

`std::map::value_compare` is a function object that compares objects of type `std::map::value_type` (key-value pairs) by comparing of the first components of the pairs.

| Member Type | Definition |
|------------------|------------|
| result_type | bool |
|first_argument_type | value_type|
|second_argument_type | value_type|

These member types are obtained via publicly inheriting std::binary_function<value_type, value_type, bool>

| Protected member objects | Definition |
|--------------------------|-------------|
| Compare comp | the stored comparator (protected member object)|

|Member functions| Definition|
|---------------|-------------|
|(constructor) | constructs a new value_compare object (protected member function)|
|operator() | compares two values of type value_type (public member function)|

# Allocator_Rebind

From [this](https://stackoverflow.com/questions/14148756/what-does-template-rebind-do) stackoverflow thread:

> rebind is defined as a structure member of the allocator class; this structure defines a member other that is defined as an instance of the allocator specialized for a different argument type (the other member defines an allocator class that can creates a different type of objects)

```cpp
 template<typename _Tp>
    class new_allocator
    {
    public:
      ...
      template<typename _Tp1>
        struct rebind
        { typedef new_allocator<_Tp1> other; };
```

```cpp
typedef typename _Alloc::template rebind<_Ty>::other _Alty;
```

The _Alloc template is used to obtain objects of some type. The container may have an internal need to allocate objects of a different type. For example, when you have a std::list<T, A>, the allocator A is meant to allocate objects of type T but the std::list<T, A> actually needs to allocate objects of some node type. Calling the node type _Ty, the std::list<T, A> needs to get hold of an allocator for _Ty objects which is using the allocation mechanism provided by A. Using

```cpp
typename _A::template rebind<_Ty>::other
```

specifies the corresponding type. Now, there are a few syntactic annoyances in this declaration:

Since rebind is a member template of _A and _A is a template argument, the rebind becomes a dependent name. To indicate that a dependent name is a template, it needs to be prefixed by template. Without the template keyword the < would be considered to be the less-than operator.
The name other also depends on a template argument, i.e., it is also a dependent name. To indicate that a dependent name is a type, the typename keyword is needed.

---

For example, given an allocator object al of type A, you can allocate an object of type _Other with the expression:

```cpp
A::rebind<Other>::other(al).allocate(1, (Other *)0)
```

Or, you can name its pointer type by writing the type:

```cpp
A::rebind<Other>::other::pointer
```
