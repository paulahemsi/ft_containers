
#ifndef BTREE_APPLY_BY_LEVEL_TPP
#define BTREE_APPLY_BY_LEVEL_TPP

#include "btree.tpp"
#include "btree.hpp"
#include <queue>

template <typename T>
void print_node_and_parent(ft::btree<T> *node, int level, bool is_first)
{
	(void) is_first;
	std::cout << RESET;
	if(!node->item)
		std::cout << std::endl;
	else
	{
		std::cout << *node->item << " (level " << level << ")";
		std::cout << CYAN;
		if(node->parent)
			std::cout << " [parent " << *node->parent->item << "]";
		std::cout << std::endl;
	}
}

template <typename T>
void print_node_infos(ft::btree<T> *node, int level, bool is_first)
{
	if (is_first)
		std::cout << CYAN;
	else
		std::cout << RESET;
	if(!node->item)
		std::cout << std::endl;
	else
		std::cout << *node->item << "(" << level << ")" << std::endl;
}

template <typename T>
void add_children_to_queue(std::queue<ft::btree<T> *> &leaf_queue, ft::btree<T> * node)
{
	if(node->left)
		leaf_queue.push(node->left);
	if(node->right)
		leaf_queue.push(node->right);
}

template <typename T>
void set_new_level(std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first)
{
	is_first = true;
	current_level++;
	leaf_queue.push(new ft::btree<int>());
}

template <typename T>
bool is_last_node(std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first, ft::btree<T> *node)
{
	if (node->item)
		return (false);
	if (leaf_queue.empty())
		return (true);
	set_new_level(leaf_queue, current_level, is_first);
	return (false);
}

template <typename T>
void btree_apply_by_level(ft::btree<T> *root, void (*applyf)(ft::btree<T> *node, int current_level, bool is_first))
{
	if (!root)
		return ;
	bool is_first = true;
	int current_level = 0;

	std::queue<ft::btree<T> *> leaf_queue;
	leaf_queue.push(root);
	leaf_queue.push(new ft::btree<int>());

	ft::btree<T> *node = NULL;
	while(true)
	{
		node = leaf_queue.front();
		leaf_queue.pop();
		applyf(node, current_level, is_first);
		is_first = false;
		if (is_last_node(leaf_queue, current_level, is_first, node))
			break;
		else
			add_children_to_queue(leaf_queue, node);
		if (!node->item)
			delete node;
	}
	if (!node->item)
			delete node;
}

#endif
