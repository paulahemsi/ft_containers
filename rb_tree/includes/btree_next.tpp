#ifndef BTREE_NEXT_TPP
#define BTREE_NEXT_TPP

#include "btree.tpp"
#include "btree_auxiliary.tpp"

template <class T>
bool is_pre_end(const ft::btree<T> *node)
{
	const ft::btree<T> *root = get_root(node);
	return (btree_end(root)->parent == node);
}

template <class T>
ft::btree<T> * find_successor_above(const ft::btree<T> *node)
{
	if (is_left_child(node->parent, node))
		return (node->parent);
	return (find_successor_above(node->parent));
}

template <class T>
ft::btree<T> * btree_next(const ft::btree<T> *node)
{
	if (!node)
		return (NULL);
	if (is_pre_end(node))
		return (node->right);
	if (is_nil(node) || is_nil(node->right))
		return (find_successor_above(node));
	else
		return (find_successor_below(node->right));
}

#endif
