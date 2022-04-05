#ifndef BTREE_END_TPP
#define BTREE_END_TPP

#include "btree.tpp"

template <class T>
ft::btree<T> * find_end(ft::btree<T> *root)
{
	if (is_nil(root->right))
		return (root->right);
	return (find_end(root->right));
}

template <class T>
ft::btree<T> * btree_end(ft::btree<T> *root)
{
	if (!root)
		return (NULL);
	return (find_end(root)); 
}


#endif
