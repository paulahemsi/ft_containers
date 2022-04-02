#ifndef BTREE_END_TPP
#define BTREE_END_TPP

#include "btree.tpp"

template <class T>
ft::btree<T> * find_end(ft::btree<T> *root)
{
	if (!root->right)
		return (root);
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
