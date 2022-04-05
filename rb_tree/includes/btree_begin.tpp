
#ifndef BTREE_BEGIN_TPP
#define BTREE_BEGIN_TPP

#include "btree.tpp"

template <class T>
ft::btree<T> * find_begin(ft::btree<T> *root)
{
	if (is_nil(root->left))
		return (root);
	return (find_begin(root->left));
}

template <class T>
ft::btree<T> * btree_begin(ft::btree<T> *root)
{
	if (!root)
		return (NULL);
	return (find_begin(root));
}

#endif
