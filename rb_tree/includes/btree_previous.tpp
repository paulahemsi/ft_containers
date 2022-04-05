#ifndef BTREE_PREVIOUS_TPP
#define BTREE_PREVIOUS_TPP

#include "btree.tpp"

template <class T>
ft::btree<T> * find_predecessor_above(const ft::btree<T> *node)
{
	if(is_right_child(node->parent, node))
		return (node->parent);
	return (find_predecessor_above(node->parent));
}

template <class T>
ft::btree<T> * btree_previous(const ft::btree<T> *node)
{
	if ((!node) || (is_root(node)))
		return (NULL);
	if (is_nil(node) || is_nil(node->left))
		return (find_predecessor_above(node));
	else
		return (find_predecessor_below(node->left));
}

#endif
