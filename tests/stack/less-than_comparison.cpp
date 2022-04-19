#include "tests.hpp"
#include <vector>
#include <list>
#include <deque>

template <typename T>
void comparison(T &foo, T &bar)
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

template <typename T>
void add_and_compare(T &foo, T &bar)
{
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

void test_less_than_comparison(void)
{
	print_title("LESS THAN COMPARISON");

	{
		print_subheading("std vector as underlying container");
		ft::stack<char, std::vector<char> > foo;
		ft::stack<char, std::vector<char> > bar;
		add_and_compare(foo, bar);
	}

	{
		print_subheading("ft::vector as underlying container");
		ft::stack<char> foo;
		ft::stack<char> bar;
		add_and_compare(foo, bar);
	}

	{
		print_subheading("std list as underlying container");
		ft::stack<char, std::list<char> > foo;
		ft::stack<char, std::list<char> > bar;
		add_and_compare(foo, bar);
	}

	{
		print_subheading("std deque as underlying container");
		ft::stack<char, std::deque<char> > foo;
		ft::stack<char, std::deque<char> > bar;
		add_and_compare(foo, bar);
	}

}
