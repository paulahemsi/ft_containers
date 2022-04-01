#ifndef BTREE_NEXT_TPP
#define BTREE_NEXT_TPP

#include "btree.hpp"

template <class T1, class T2>
ft::btree<T1, T2> * find_successor_above(const ft::btree<T1, T2> *node)
{
	if(is_left_child(node->parent, node))
		return (node->parent);
	return (find_successor_above(node->parent));
}

template <class T1, class T2>
ft::btree<T1, T2> * btree_next(const ft::btree<T1, T2> *node)
{
	if ((!node) || (is_root(node)))
		return (NULL);
	if (node->right)
		return (find_successor_below(node->right));
	else
		return (find_successor_above(node));
}

#endif
