
#ifndef BTREE_SEARCH_ITEM_TPP
#define BTREE_SEARCH_ITEM_TPP

#include "btree.tpp"

template< class T1, class T2, class Compare>
const ft::pair<T1, T2> *btree_search_item(ft::btree<T1, T2> *root, T1 data_ref)
{
	Compare compare;
	
	if (root == NULL)
		return (NULL);
	if (root->item->first == data_ref)
		return (root->item);
	if (compare(data_ref, root->item->first))
		return (btree_search_item<T1, T2, std::less<T1> >(root->left, data_ref));
	else
		return (btree_search_item<T1, T2, std::less<T1> >(root->right, data_ref));
}

template< class T1, class T2, class Compare>
ft::btree<T1, T2> *btree_search_node(ft::btree<T1, T2> *root, T1 data_ref)
{
	Compare compare;
	
	if (root == NULL)
		return (NULL);
	if (root->item->first == data_ref)
		return (root);
	if (compare(data_ref, root->item->first))
		return (btree_search_node<T1, T2, std::less<T1> >(root->left, data_ref));
	else
		return (btree_search_node<T1, T2, std::less<T1> >(root->right, data_ref));
}

#endif
