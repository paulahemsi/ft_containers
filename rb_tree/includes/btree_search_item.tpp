
#ifndef BTREE_SEARCH_ITEM_TPP
#define BTREE_SEARCH_ITEM_TPP

#include "btree.tpp"

template<class T, class Compare>
const T *btree_search_item(ft::btree<T> *root, const T data_ref, Compare compare)
{
	if (!root || is_nil(root))
		return (NULL);
	if (is_equal(data_ref, *(root->item), compare))
		return (root->item);
	if (compare(data_ref, *(root->item)))
		return (btree_search_item<T>(root->left, data_ref, compare));
	return (btree_search_item<T>(root->right, data_ref, compare));
}

template<class T, class Compare>
ft::btree<T> *btree_search_node(ft::btree<T> *root, const T data_ref, Compare compare)
{
	if (!root || is_nil(root))
		return (NULL);
	if (is_equal(data_ref, *(root->item), compare))
		return (root);
	if (compare(data_ref, *(root->item)))
		return (btree_search_node(root->left, data_ref, compare));
	return (btree_search_node(root->right, data_ref, compare));
}

#endif
