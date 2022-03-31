
#ifndef BTREE_ROTATE_AUX_TPP
#define BTREE_ROTATE_AUX_TPP

#include "btree.tpp"

template <class T1, class T2>
bool node_to_rotate_was_parent_left_child(ft::btree<T1, T2> *parent, ft::btree<T1, T2> *node_to_rotate)
{
	return (parent->left == node_to_rotate);
}

template <class T1, class T2>
void update_parent_child(ft::btree<T1, T2> *node_to_rotate, ft::btree<T1, T2> *new_root)
{
	if (node_to_rotate_was_parent_left_child(new_root->parent, node_to_rotate))
		new_root->parent->left = new_root;
	else
		new_root->parent->right = new_root;
}

#endif
