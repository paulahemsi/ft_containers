
#ifndef BTREE_DELETE_TREE_TPP
#define BTREE_DELETE_TREE_TPP

#include "btree.tpp"

template <class T1, class T2>
void btree_delete_tree(ft::btree<T1, T2> *root)
{
	if (root == NULL)
		return ;
	btree_delete_tree(root->left);
	btree_delete_tree(root->right);
	if (root->item)
		delete root->item;
	delete root;
}

#endif
