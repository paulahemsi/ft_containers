
#ifndef BTREE_APPLY_SUFFIX_TPP
#define BTREE_APPLY_SUFFIX_TPP

#include "btree.tpp"

template <typename T>
void btree_apply_suffix(ft::btree<T> *root, void (*applyf)(T *))
{
    if (!root)
        return;
    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);
    applyf(root->item);
}

#endif
