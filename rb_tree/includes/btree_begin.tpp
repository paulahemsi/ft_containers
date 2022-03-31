
#ifndef BTREE_BEGIN_TPP
#define BTREE_BEGIN_TPP

#include "btree.hpp"

template <class T1, class T2>
ft::btree<T1, T2> * find_begin(ft::btree<T1, T2> *root)
{
	if (!root->left)
		return (root);
	return (find_begin(root->left));
}

template <class T1, class T2>
ft::btree<T1, T2> * btree_begin(ft::btree<T1, T2> *root)
{
	if (!root)
		return (NULL);
	return (find_begin(root));
}

#endif
