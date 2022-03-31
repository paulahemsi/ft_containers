
#ifndef BTREE_SEARCH_ITEM_TPP
#define BTREE_SEARCH_ITEM_TPP

#include "btree.tpp"

template <class T1, class T2>
const ft::pair<T1, T2> *btree_search_item(ft::btree<T1, T2> *root, T1 data_ref,  bool (*compare)(const T1 &, const T1 &))
{
	if (root == NULL)
		return (NULL);
	if (root->item->first == data_ref)
		return (root->item);
	if (compare(data_ref, root->item->first))
		return (btree_search_item(root->right, data_ref, compare));
	else
		return (btree_search_item(root->left, data_ref, compare));
}

template <class T1, class T2>
ft::btree<T1, T2> *btree_search_node(ft::btree<T1, T2> *root, T1 data_ref,  bool (*compare)(const T1 &, const T1 &))
{
	if (root == NULL)
		return (NULL);
	if (root->item->first == data_ref)
		return (root);
	if (compare(data_ref, root->item->first))
		return (btree_search_node(root->right, data_ref, compare));
	else
		return (btree_search_node(root->left, data_ref, compare));
}

#endif
