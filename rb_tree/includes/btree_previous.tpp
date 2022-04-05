#ifndef BTREE_PREVIOUS_TPP
#define BTREE_PREVIOUS_TPP

#include "btree.tpp"
#include "btree_auxiliary.tpp"

template <class T>
bool is_begin(const ft::btree<T> *node)
{
	const ft::btree<T> *root = get_root(node);
	return (btree_begin(root)->parent == node);
}

template <class T>
ft::btree<T> * find_predecessor_above(const ft::btree<T> *node)
{
	if (is_right_child(node->parent, node))
		return (node->parent);
	return (find_predecessor_above(node->parent));
}

template <class T>
ft::btree<T> * btree_previous(const ft::btree<T> *node)
{
	if (!node)
		return (NULL);
	if (is_begin(node))
		return (node->left);
	if (is_nil(node) || is_nil(node->left))
		return (find_predecessor_above(node));
	else
		return (find_predecessor_below(node->left));
}

#endif
