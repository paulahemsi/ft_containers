

#ifndef BTREE_APPLY_INFIX_TPP
#define BTREE_APPLY_INFIX_TPP

#include "btree.tpp"

template <class T1, class T2>
void btree_apply_infix(ft::btree<T1, T2> *root, void (*applyf)(const ft::pair<T1, T2> *))
{
	if (!root)
		return;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}

#endif
