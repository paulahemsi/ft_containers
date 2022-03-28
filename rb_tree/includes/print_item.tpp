
#ifndef PRINT_ITEM_TPP
#define PRINT_ITEM_TPP

#include <iostream>

template <typename T>
void print_item(T *item)
{
	std::cout << *item << ' ' << *item << std::endl;
}

template <typename T>
void print_rb_node_infos(ft::btree<T> *node, int level, bool is_first)
{
	(void) is_first;
	std::cout << RESET;
	if(!node->item)
		std::cout << std::endl;
	else
	{
		if (node->color)
			std::cout << BOLD;
		else
			std::cout << C_RED;
		std::cout << *node->item << RESET << " (level " << level << ")";
		std::cout << CYAN;
		if(node->parent)
			std::cout << " [parent " << *node->parent->item << "]";
		std::cout << std::endl;
	}
}

#endif
