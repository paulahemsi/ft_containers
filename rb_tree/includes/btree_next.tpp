#ifndef BTREE_NEXT_TPP
#define BTREE_NEXT_TPP

#include "btree.tpp"

template <class T>
ft::btree<T> * find_successor_above(const ft::btree<T> *node)
{
	if(is_left_child(node->parent, node))
		return (node->parent);
	return (find_successor_above(node->parent));
}

template <class T>
ft::btree<T> * btree_next(const ft::btree<T> *node)
{
	if ((!node) || (is_last_node(node)))
		return (NULL);
	if (is_nil(node) || is_nil(node->right))
		return (find_successor_above(node));
	else
		return (find_successor_below(node->right));
}

#endif
