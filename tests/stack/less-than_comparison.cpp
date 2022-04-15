#include "tests.hpp"

template <typename T>
void comparison(ft::stack<T> &foo, ft::stack<T> &bar)
{
	if (foo< bar)
		std::cout << "foo is less than bar\n";
	if (foo> bar)
		std::cout << "foo is greater than bar\n";
	if (foo<=bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar)
		std::cout << "foo is greater than or equal to bar\n";
}

void test_less_than_comparison(void)
{
	print_title("LESS THAN COMPARISON");

	ft::stack<char> foo;
	ft::stack<char> bar;
	
	print_subheading("Same size and values");
	foo.push('a');
	foo.push('b');
	bar.push('a');
	bar.push('b');
	comparison(foo, bar);

	print_subheading("Same size diferent values");
	foo.push('c');
	bar.push('d');
	comparison(foo, bar);

	print_subheading("same values, diferent sizes");
	bar.pop();
	bar.push('c');
	bar.push('d');
	comparison(foo, bar);
}
