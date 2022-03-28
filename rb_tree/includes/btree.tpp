
#ifndef BTREE_TPP
#define BTREE_TPP

#include <iostream>

#define	RED				0
#define	BLACK			1
#define	DOUBLE_BLACK	2

namespace ft
{
	typedef	int	t_color;

	template <typename T>
	struct btree
	{
		struct btree	*left;
		struct btree	*right;
		struct btree	*parent;
		t_color			color;
		T				*item;

		btree(void): left(NULL), right(NULL), parent(NULL), color(RED), item(NULL) {}
		btree(T *new_item): left(NULL), right(NULL), parent(NULL), color(RED), item(new_item) {}
		btree(T *new_item, bool is_black): left(NULL), right(NULL), parent(NULL), color(is_black), item(new_item) {}
		~btree(void) {}
	};
};

#endif
