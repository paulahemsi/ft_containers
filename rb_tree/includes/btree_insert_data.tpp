
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "rb_tree.hpp"

template< class T1, class T2 >
ft::btree<T1, T2> * get_sibling(ft::btree<T1, T2> *node)
{
	if (is_left_child(node->parent, node))
		return node->parent->right;
	return node->parent->left;
}

template< class T1, class T2 >
bool sibling_is_red(ft::btree<T1, T2> *node)
{
	ft::btree<T1, T2> *sibling = get_sibling(node);

	if (!sibling)
		return (false);
	if (sibling->color == RED)
		return (true);
	return (false);
}

template< class T1, class T2 >
void recolor(ft::btree<T1, T2> *node)
{
	node->color = !node->color;
}

template< class T1, class T2 >
void recolor_node_and_sibling(ft::btree<T1, T2> *node)
{
	recolor(node);
	recolor(get_sibling(node));
}

template< class T1, class T2 >
void check_rules(ft::btree<T1, T2> *node)
{
	ft::btree<T1, T2> *parent = node->parent;
	ft::btree<T1, T2> *grandma = parent->parent;

	if (parent->color == BLACK)
		return ;
	if (sibling_is_red(parent))
	{
		recolor_node_and_sibling(parent);
		if (is_root(grandma))
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

template< class T1, class T2, class Compare>
void btree_insert_data_recursive(ft::btree<T1, T2> **root, ft::btree<T1, T2> *parent, const ft::pair<T1,T2> *new_pair)
{
	Compare compare;

	if (*root == NULL)
	{
		*root = new ft::btree<T1, T2>(new_pair);
		(*root)->parent = parent;
		check_rules(*root);
		return ;
	}
	if (compare(new_pair->first, (*root)->item->first))
		btree_insert_data_recursive<T1, T2, Compare>(&(*root)->left, *root, new_pair);
	else
		btree_insert_data_recursive<T1, T2, Compare>(&(*root)->right, *root, new_pair);
}

template< class T1, class T2 >
void	update_root(ft::btree<T1, T2> **root)
{
	if (is_root(*root))
		return ;
	*root = get_root(*root);
}

template< class T1, class T2, class Compare>
void btree_insert_data(ft::btree<T1, T2> **root, const ft::pair<T1,T2> *new_pair)
{
	Compare compare;

	if (*root == NULL)
	{
		*root = new ft::btree<T1, T2>(new_pair, BLACK);
		return ;
	}
	if (compare(new_pair->first, (*root)->item->first))
		btree_insert_data_recursive<T1, T2, Compare>(&(*root)->left, *root, new_pair);
	else
		btree_insert_data_recursive<T1, T2, Compare>(&(*root)->right, *root, new_pair);
	update_root(root);
}

#endif
