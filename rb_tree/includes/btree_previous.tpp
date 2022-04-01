#ifndef BTREE_PREVIOUS_TPP
#define BTREE_PREVIOUS_TPP

#include "btree.hpp"

template <class T1, class T2>
ft::btree<T1, T2> * find_predecessor_above(const ft::btree<T1, T2> *node)
{
	if(is_right_child(node->parent, node))
		return (node->parent);
	return (find_predecessor_above(node->parent));
}

template <class T1, class T2>
ft::btree<T1, T2> * btree_previous(const ft::btree<T1, T2> *node)
{
	if ((!node) || (is_root(node)))
		return (NULL);
	if (node->left)
		return (find_predecessor_below(node->left));
	else
		return (find_predecessor_above(node));
}

#endif
