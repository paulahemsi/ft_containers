
#ifndef BTREE_INSERT_DATA_TPP
#define BTREE_INSERT_DATA_TPP

#include "btree.tpp"
#include "btree_create_node.tpp"
#include "btree_auxiliary.tpp"
#include "btree_right_rotate.tpp"
#include "btree_left_rotate.tpp"

template<class T>
ft::btree<T> * get_sibling(ft::btree<T> *node)
{
	if (is_left_child(node->parent, node))
		return node->parent->right;
	return node->parent->left;
}

template<class T>
bool sibling_is_red(ft::btree<T> *node)
{
	ft::btree<T> *sibling = get_sibling(node);

	if (is_nil(sibling))
		return (false);
	if (sibling->color == RED)
		return (true);
	return (false);
}

template<class T>
void recolor(ft::btree<T> *node)
{
	node->color = !node->color;
}

template<class T>
void recolor_node_and_sibling(ft::btree<T> *node)
{
	recolor(node);
	recolor(get_sibling(node));
}

template<class T>
void check_rules(ft::btree<T> *node)
{
	ft::btree<T> *parent = node->parent;
	ft::btree<T> *grandma = parent->parent;

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
	if (is_left_child(grandma, parent) != is_left_child(parent, node))
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

template<class T, class Compare, class Alloc>
void	btree_insert_data_recursive(ft::btree<T> **root, ft::btree<T> *parent, T *item, Compare compare, Alloc alloc)
{
	if (is_nil(*root))
	{
		alloc.deallocate(*root, 1);
		*root = btree_create_node(item, alloc);
		(*root)->parent = parent;
		check_rules(*root);
		return ;
	}
	if (is_equal(*item, *((*root)->item), compare))
		return ;
	if (compare(*item, *((*root)->item)))
		return (btree_insert_data_recursive<T>(&(*root)->left, *root, item, compare, alloc));
	return (btree_insert_data_recursive<T>(&(*root)->right, *root, item, compare, alloc));
}

template<class T>
void	update_root(ft::btree<T> **root)
{
	if (is_root(*root))
		return ;
	*root = get_root(*root);
}

template<class T, class Compare, class Alloc>
void	btree_insert_data(ft::btree<T> **root, T *item, Compare compare, Alloc alloc)
{
	if (*root == NULL)
	{
		*root = btree_create_root(item, alloc);
		return ;
	}
	if (is_equal(*item, *((*root)->item), compare))
		return ;
	if (compare(*item, *((*root)->item)))
		btree_insert_data_recursive<T>(&(*root)->left, *root, item, compare, alloc);
	else
		btree_insert_data_recursive<T>(&(*root)->right, *root, item, compare, alloc);
	update_root(root);
}

#endif
