
#ifndef BTREE_APPLY_SUFFIX_TPP
#define BTREE_APPLY_SUFFIX_TPP

#include "btree.tpp"

template <class T1, class T2>
void btree_apply_suffix(ft::btree<T1, T2> *root, void (*applyf)(ft::pair<T1, T2> *))
{
    if (!root)
        return;
    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);
    applyf(root->item);
}

#endif
