
#ifndef BTREE_DELETE_TPP
#define BTREE_DELETE_TPP

#include "btree.tpp"
#include "btree_delete_rules.tpp"

template <class T1, class T2>
ft::btree<T1, T2> * find_neighbor(ft::btree<T1, T2> *node)
{
	if (node->left)
		return (find_predecessor_below(node->left));
	else
		return (find_successor_below(node->right));
}

template <class T1, class T2>
void replace_content(ft::btree<T1, T2> *node, ft::btree<T1, T2> *node_to_replace)
{
	node->item = node_to_replace->item;
}

template <class T1, class T2>
void delete_node(ft::btree<T1, T2> *node)
{
	check_delete_rules(node);
	if (is_left_child(node->parent, node))
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	delete node;
}

template <class T1, class T2>
void btree_delete_recursive(ft::btree<T1, T2> *node_to_delete)
{
	if (is_leaf(node_to_delete))
		return (delete_node(node_to_delete));
	ft::btree<T1, T2> * node_to_replace = find_neighbor(node_to_delete);
	replace_content(node_to_delete, node_to_replace);
	return (btree_delete_recursive(node_to_replace));
}

template <class T1, class T2>
const ft::pair<T1, T2> * btree_delete(ft::btree<T1, T2> **root, T1 data_ref)
{
	ft::btree<T1, T2> * node_to_delete = btree_search_node<T1, T2, std::less<T1> >(*root, data_ref);
	if (!node_to_delete)
		return (NULL);
	const ft::pair<T1, T2> * item_to_return = node_to_delete->item;
	if (is_last_node(node_to_delete))
	{
		delete node_to_delete;
		*root = NULL;
	}
	else
	{
		btree_delete_recursive(node_to_delete);
		update_root(root);
	}
	return (item_to_return);
}

#endif
