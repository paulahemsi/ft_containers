
#ifndef BTREE_SEARCH_ITEM_TPP
#define BTREE_SEARCH_ITEM_TPP

#include "btree.tpp"

template<class T>
const T *btree_search_item(ft::btree<T> *root, const T data_ref, int (*compare)(const T*, const T*))
{
	if (!root || is_nil(root))
		return (NULL);
	if (data_ref.first == root->item->first)
		return (root->item);
	if (compare(&data_ref, root->item) == 1)
		return (btree_search_item<T>(root->right, data_ref, compare));
	return (btree_search_item<T>(root->left, data_ref, compare));
}

template<class T>
ft::btree<T> *btree_search_node(ft::btree<T> *root, const T data_ref, int (*compare)(const T*, const T*))
{
	if (!root || is_nil(root))
		return (NULL);
	if (data_ref.first == root->item->first)
		return (root);
	if (compare(&data_ref, root->item) == 1)
		return (btree_search_node<T>(root->right, data_ref, compare));
	return (btree_search_node<T>(root->left, data_ref, compare));
}

#endif
