
#ifndef PRINT_ITEM_TPP
#define PRINT_ITEM_TPP

#include <iostream>
#include "btree.tpp"

# define CYAN			"\e[0;36m"
# define C_RED			"\e[0;31m"
# define RESET			"\e[0m"
# define BOLD			"\e[1m"

template <class T>
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
		std::cout << "key:" << node->item->first << " value: " << node->item->second << RESET << " (level " << level << ")";
		std::cout << CYAN;
		if(node->parent)
			std::cout << " [parent " << "key:" << node->parent->item->first << " value: " << node->parent->item->second << "]";
		std::cout << std::endl;
	}
}

#endif
