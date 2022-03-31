
#ifndef BTREE_RIGHT_ROTATE_TPP
#define BTREE_RIGHT_ROTATE_TPP

#include "btree.tpp"
#include "btree_rotate_aux.tpp"


template <class T1, class T2>
void update_old_root_rr(ft::btree<T1, T2> *old_root, ft::btree<T1, T2> *new_root)
{
	old_root->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = old_root;
}

template <class T1, class T2>
void update_new_root_rr(ft::btree<T1, T2> *old_root, ft::btree<T1, T2> *new_root, ft::btree<T1, T2> *parent)
{
	new_root->right = old_root;
	old_root->parent = new_root;
	new_root->parent = parent;
	if (new_root->parent)
		update_parent_child(old_root, new_root);
}

template <class T1, class T2>
ft::btree<T1, T2> * btree_right_rotate(ft::btree<T1, T2> *old_root)
{
	if (!old_root->left)
		return (NULL);

	ft::btree<T1, T2> *parent = old_root->parent;
	ft::btree<T1, T2> *new_root = old_root->left;

	update_old_root_rr(old_root, new_root);
	update_new_root_rr(old_root, new_root, parent);
	return (new_root);
}

#endif
