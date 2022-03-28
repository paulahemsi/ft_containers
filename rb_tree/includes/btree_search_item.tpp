
#ifndef BTREE_SEARCH_ITEM_TPP
#define BTREE_SEARCH_ITEM_TPP

#include "btree.tpp"

template <typename T>
T *btree_search_item(ft::btree<T> *root, T data_ref,  bool (*compare)(T *, T *))
{
	if (root == NULL)
		return (NULL);
	if (*root->item == data_ref)
		return (root->item);
	if (compare(&data_ref, root->item))
		return (btree_search_item(root->right, data_ref, compare));
	else
		return (btree_search_item(root->left, data_ref, compare));
}

template <typename T>
ft::btree<T> *btree_search_node(ft::btree<T> *root, T data_ref,  bool (*compare)(T *, T *))
{
	if (root == NULL)
		return (NULL);
	if (*root->item == data_ref)
		return (root);
	if (compare(&data_ref, root->item))
		return (btree_search_node(root->right, data_ref, compare));
	else
		return (btree_search_node(root->left, data_ref, compare));
}

#endif
