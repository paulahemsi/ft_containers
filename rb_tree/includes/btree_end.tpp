#ifndef BTREE_END_TPP
#define BTREE_END_TPP

#include "btree.tpp"

template <class T1, class T2>
ft::btree<T1, T2> * find_end(ft::btree<T1, T2> *root)
{
	if (!root->right)
		return (root);
	return (find_end(root->right));
}

template <class T1, class T2>
ft::btree<T1, T2> * btree_end(ft::btree<T1, T2> *root)
{
	if (!root)
		return (NULL);
	return (find_end(root)); 
}


#endif
