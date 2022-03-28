

#ifndef BTREE_APPLY_INFIX_TPP
#define BTREE_APPLY_INFIX_TPP

#include "btree.tpp"

template <typename T>
void btree_apply_infix(ft::btree<T> *root, void (*applyf)(T *))
{
	if (!root)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->item);
    btree_apply_infix(root->right, applyf);
}

#endif
