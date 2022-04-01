
#ifndef BTREE_AUXILIARY_TPP
#define BTREE_AUXILIARY_TPP

#include "btree.hpp"

template <class T1, class T2>
ft::btree<T1, T2> * find_successor_below(ft::btree<T1, T2> *node)
{
	if (!node->left)
		return (node);
	return (find_successor_below(node->left));
}

template <class T1, class T2>
ft::btree<T1, T2> * find_predecessor_below(ft::btree<T1, T2> *node)
{
	if (!node->right)
		return (node);
	return (find_predecessor_below(node->right));
}

template< class T1, class T2 >
ft::btree<T1, T2> * get_root(ft::btree<T1, T2> *node)
{
	ft::btree<T1, T2> *tmp = node;

	while (tmp->parent)
		tmp = tmp->parent;
	return (tmp);
}

template< class T1, class T2 >
bool is_root(const ft::btree<T1, T2> *node)
{
	return (node->parent == NULL);
}

template< class T1, class T2 >
bool is_left_child(const ft::btree<T1, T2> *parent, const ft::btree<T1, T2> *node)
{
	return (parent->left == node);
}

#endif
