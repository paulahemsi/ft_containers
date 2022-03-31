
#ifndef BTREE_APPLY_PREFIX_TPP
#define BTREE_APPLY_PREFIX_TPP

#include "btree.tpp"

template <class T1, class T2>
void btree_apply_prefix(ft::btree<T1, T2> *root, void (*applyf)(ft::pair<T1, T2> *))
{
	if (!root)
        return;
    applyf(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}

#endif
