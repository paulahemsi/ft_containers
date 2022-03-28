
#ifndef BTREE_APPLY_PREFIX_TPP
#define BTREE_APPLY_PREFIX_TPP

#include "btree.tpp"

template <typename T>
void btree_apply_prefix(ft::btree<T> *root, void (*applyf)(T *))
{
	if (!root)
        return;
    applyf(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}

#endif
