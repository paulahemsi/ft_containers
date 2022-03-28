
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "btree.hpp"

template <typename T>
ft::btree<T> * get_root(ft::btree<T> *node)
{
	ft::btree<T> *tmp = node;

	while (tmp->parent)
		tmp = tmp->parent;
	return (tmp);
}

template <typename T>
bool is_tree_root(ft::btree<T> *node)
{
	return (node->parent == NULL);
}

template <typename T>
bool is_left_child(ft::btree<T> *parent, ft::btree<T> *node)
{
	return (parent->left == node);
}

template <typename T>
ft::btree<T> * get_sibling(ft::btree<T> *node)
{
	if (is_left_child(node->parent, node))
		return node->parent->right;
	return node->parent->left;
}

template <typename T>
bool sibling_is_red(ft::btree<T> *node)
{
	ft::btree<T> *sibling = get_sibling(node);
	
	if (!sibling)
		return (false);
	if (sibling->color == RED)
		return (true);
	return (false);
}

template <typename T>
void recolor(ft::btree<T> *node)
{
	node->color = !node->color;
}

template <typename T>
bool node_is_root(ft::btree<T> *node)
{
	return (node->parent == NULL);
}

template <typename T>
void recolor_node_and_sibling(ft::btree<T> *node)
{
	recolor(node);
	recolor(get_sibling(node));
}

template <typename T>
void check_rules(ft::btree<T> *node)
{
	ft::btree<T> *parent = node->parent;
	ft::btree<T> *grandma = parent->parent;
	
	if (parent->color == BLACK)
		return ;
	if (sibling_is_red(parent))
	{
		recolor_node_and_sibling(parent);
		if (node_is_root(grandma))
			return ;
		recolor(grandma);
		return check_rules(grandma);
	}
	if (is_left_child(grandma, parent) != is_left_child (parent, node))
	{
		if (is_left_child(parent, node))
			parent = btree_right_rotate(parent);
		else
			parent = btree_left_rotate(parent);
	}
	recolor(grandma);
	recolor(parent);
	if (is_left_child(grandma, parent))
		grandma = btree_right_rotate(grandma);
	else
		grandma = btree_left_rotate(grandma);
}

template <typename T>
void btree_insert_data_recursive(ft::btree<T> **root, ft::btree<T> *parent, T *new_item, bool (*compare)(T *, T *))
{
	if (*root == NULL)
	{
		*root = new ft::btree<int>(new_item);
		(*root)->parent = parent;
		check_rules(*root);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data_recursive(&(*root)->right, *root, new_item, compare);
	else
		btree_insert_data_recursive(&(*root)->left, *root, new_item, compare);
}

template <typename T>
void	update_root(ft::btree<T> **root)
{
	if (is_tree_root(*root))
		return ;
	*root = get_root(*root);
}

template <typename T>
void btree_insert_data(ft::btree<T> **root, T *new_item, bool (*compare)(T *, T *))
{
	if (*root == NULL)
	{
		*root = new ft::btree<int>(new_item, BLACK);
		return ;
	}
	if (compare(new_item, (*root)->item))
		btree_insert_data_recursive(&(*root)->right, *root, new_item, compare);
	else
		btree_insert_data_recursive(&(*root)->left, *root, new_item, compare);
	update_root(root);
}

#endif
