
#ifndef BTREE_DELETE_TPP
#define BTREE_DELETE_TPP

#include "btree.tpp"
#include "btree_create_node.tpp"
#include "btree_delete_rules.tpp"

template <class T>
ft::btree<T> * find_neighbor(ft::btree<T> *node)
{
	if (!is_nil(node->left))
		return (find_predecessor_below(node->left));
	else
		return (find_successor_below(node->right));
}

template <class T>
void replace_content(ft::btree<T> *node, ft::btree<T> *node_to_replace)
{
	node->item = node_to_replace->item;
}

template <class T, class Alloc>
void	delete_leaf(ft::btree<T> *leaf, Alloc alloc)
{
	alloc.deallocate(leaf->right, 1);
	alloc.deallocate(leaf->left, 1);
	alloc.deallocate(leaf, 1);
}

template <class T, class Alloc>
void delete_node(ft::btree<T> *node, Alloc alloc)
{
	check_delete_rules(node);
	if (is_left_child(node->parent, node))
		node->parent->left = create_nil_node(node->parent, alloc);
	else
		node->parent->right = create_nil_node(node->parent, alloc);
	delete_leaf(node, alloc);
}

template <class T, class Alloc>
void btree_delete_recursive(ft::btree<T> *node_to_delete, Alloc alloc)
{
	if (is_leaf(node_to_delete))
		return (delete_node(node_to_delete, alloc));
	ft::btree<T> * node_to_replace = find_neighbor(node_to_delete);
	replace_content(node_to_delete, node_to_replace);
	return (btree_delete_recursive(node_to_replace, alloc));
}

template <class T, class Compare, class Alloc>
T * btree_delete(ft::btree<T> **root, T data_ref, Compare compare, Alloc alloc)
{
	ft::btree<T> * node_to_delete = btree_search_node<T>(*root, data_ref, compare);
	if (!node_to_delete)
		return (NULL);
	const T * item_to_return = node_to_delete->item;
	if (is_last_node(node_to_delete))
	{
		delete_leaf(node_to_delete, alloc);
		*root = NULL;
	}
	else
	{
		btree_delete_recursive(node_to_delete, alloc);
		update_root(root);
	}
	return (const_cast<T *>(item_to_return));
}

#endif
