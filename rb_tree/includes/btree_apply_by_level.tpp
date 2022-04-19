
#ifndef BTREE_APPLY_BY_LEVEL_TPP
#define BTREE_APPLY_BY_LEVEL_TPP

#include "btree.tpp"
#include <queue>

template <class T>
void print_node_and_parent(ft::btree<T> *node, int level, bool is_first)
{
	(void) is_first;
	std::cout << RESET;
	if(!node->item)
		std::cout << std::endl;
	else
	{
		std::cout << "key: "<< node->item->first << " value: " << node->item->second << " (level " << level << ")";
		std::cout << CYAN;
		if(node->parent)
			std::cout << " [parent " << "key: "<< node->parent->item->first << " value: " << node->parent->item->second << "]";
		std::cout << std::endl;
	}
}

template <class T>
void print_node_infos(ft::btree<T> *node, int level, bool is_first)
{
	if (is_first)
		std::cout << CYAN;
	else
		std::cout << RESET;
	if(!node->item)
		std::cout << std::endl;
	else
		std::cout << "key: "<< node->item->first << " value: " << node->item->second << "(" << level << ")" << std::endl;
}

template <class T>
void add_children_to_queue(std::queue<ft::btree<T> *> &leaf_queue, ft::btree<T> * node)
{
	if(!is_nil(node->left))
		leaf_queue.push(node->left);
	if(!is_nil(node->right))
		leaf_queue.push(node->right);
}

template <class T, class Alloc>
void set_new_level(std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first, Alloc alloc)
{
	is_first = true;
	current_level++;
	ft::btree<T> *new_level_node = alloc.allocate(1);
	alloc.construct(new_level_node, ft::btree<T>());
	leaf_queue.push(new_level_node);
}

template <class T, class Alloc>
bool is_last_node(std::queue<ft::btree<T> *> &leaf_queue, int &current_level, bool &is_first, ft::btree<T> *node, Alloc alloc)
{
	if (node->item)
		return (false);
	if (leaf_queue.empty())
		return (true);
	set_new_level(leaf_queue, current_level, is_first, alloc);
	return (false);
}

template <class T, class Alloc>
void btree_apply_by_level(ft::btree<T> *root, void (*applyf)(ft::btree<T> *node, int current_level, bool is_first), Alloc alloc)
{
	if (!root)
		return ;
	bool is_first = true;
	int current_level = 0;

	std::queue<ft::btree<T> *> leaf_queue;
	leaf_queue.push(root);
	leaf_queue.push(new ft::btree<T>(NULL));

	ft::btree<T> *node = NULL;
	while(true)
	{
		node = leaf_queue.front();
		leaf_queue.pop();
		applyf(node, current_level, is_first);
		is_first = false;
		if (is_last_node(leaf_queue, current_level, is_first, node, alloc))
			break;
		else if (!is_nil(node))
			add_children_to_queue(leaf_queue, node);
		if (!node->item)
			alloc.deallocate(node, 1);
	}
	if (!node->item)
		alloc.deallocate(node, 1);
}

#endif
