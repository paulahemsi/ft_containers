
#ifndef BTREE_TPP
#define BTREE_TPP

#include <iostream>
#include "pair.tpp"

#define	RED				0
#define	BLACK			1
#define	DOUBLE_BLACK	2

namespace ft
{
	typedef	int	t_color;

	template <class T1, class T2>
	struct btree
	{
		struct btree			*left;
		struct btree			*right;
		struct btree			*parent;
		t_color					color;
		const ft::pair<T1, T2>	*item;

		btree(void): left(NULL), right(NULL), parent(NULL), color(RED), item(NULL) {}
		btree(const ft::pair<T1, T2> *new_item): left(NULL), right(NULL), parent(NULL), color(RED), item(new_item) {}
		btree(const ft::pair<T1, T2> *new_item, bool is_black): left(NULL), right(NULL), parent(NULL), color(is_black), item(new_item) {}
		~btree(void) {}
	};
};

#endif
