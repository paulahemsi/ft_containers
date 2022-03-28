
#ifndef BTREE_ROTATE_AUX_TPP
#define BTREE_ROTATE_AUX_TPP

#include "btree.tpp"

template <typename T>
bool node_to_rotate_was_parent_left_child(ft::btree<T> *parent, ft::btree<T> *node_to_rotate)
{
	return (parent->left == node_to_rotate);
}

template <typename T>
void update_parent_child(ft::btree<T> *node_to_rotate, ft::btree<T> *new_root)
{
	if (node_to_rotate_was_parent_left_child(new_root->parent, node_to_rotate))
		new_root->parent->left = new_root;
	else
		new_root->parent->right = new_root;
}

#endif
