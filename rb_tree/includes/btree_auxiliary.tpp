
#ifndef BTREE_AUXILIARY_TPP
#define BTREE_AUXILIARY_TPP

#include "btree.tpp"

template <class T>
bool is_nil(const ft::btree<T> *node)
{
	if (!node->item && !node->left && !node->right)
		return (true);
	return (false);
}

template <class T>
ft::btree<T> * find_successor_below(ft::btree<T> *node)
{
	if (is_nil(node->left))
		return (node);
	return (find_successor_below(node->left));
}

template <class T>
ft::btree<T> * find_predecessor_below(ft::btree<T> *node)
{
	if (is_nil(node->right))
		return (node);
	return (find_predecessor_below(node->right));
}

template <class T>
ft::btree<T> * get_root(ft::btree<T> *node)
{
	ft::btree<T> *tmp = node;

	while (tmp->parent)
		tmp = tmp->parent;
	return (tmp);
}

template <class T>
const ft::btree<T> * get_root(const ft::btree<T> *node)
{
	const ft::btree<T> *tmp = node;

	while (tmp->parent)
		tmp = tmp->parent;
	return (tmp);
}

template <class T>
bool is_root(const ft::btree<T> *node)
{
	return (node->parent == NULL);
}

template <class T>
bool is_left_child(const ft::btree<T> *parent, const ft::btree<T> *node)
{
	return (parent->left == node);
}

template <class T>
bool is_right_child(const ft::btree<T> *parent, const ft::btree<T> *node)
{
	return (parent->right == node);
}

template <class T>
bool is_leaf(const ft::btree<T> *node)
{
	if (is_nil(node->left) && is_nil(node->right))
		return (true);
	return (false);
}

template <class T>
bool is_last_node(const ft::btree<T> *node)
{
	return (is_root(node) && is_leaf(node));
}

#endif
