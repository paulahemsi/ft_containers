
#ifndef BTREE_LEVEL_COUNT_TPP
#define BTREE_LEVEL_COUNT_TPP

#include "btree.tpp"

template <class T1, class T2>
size_t max_depth(size_t left_depth, size_t right_depth, ft::btree<T1, T2> *root)
{
	root++;
	root--;
	if (left_depth > right_depth)
		return (left_depth);
	return (right_depth);
}

template <class T1, class T2>
size_t btree_level_count(ft::btree<T1, T2> *root)
{
	if (!root || (!root->left && !root->right))
		return (0);
	size_t left_level = btree_level_count(root->left);
	size_t right_level = btree_level_count(root->right);
	return (1 + max_depth(left_level, right_level, root));
}

#endif
