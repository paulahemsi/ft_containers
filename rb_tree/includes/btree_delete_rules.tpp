
#ifndef BTREE_DELETE_RULES_TPP
#define BTREE_DELETE_RULES_TPP

#include "btree.tpp"

template <class T1, class T2>
void deal_double_black(ft::btree<T1, T2> *double_black_node);

template <class T1, class T2>
ft::btree<T1, T2> * get_opposite_niece(ft::btree<T1, T2> *node, ft::btree<T1, T2> *sibling)
{
	if (is_left_child(node->parent, node))
		return (sibling->right);
	return (sibling->left);
}

template <class T1, class T2>
ft::btree<T1, T2> * get_same_direction_niece(ft::btree<T1, T2> *node, ft::btree<T1, T2> *sibling)
{
	if (is_left_child(node->parent, node))
		return (sibling->left);
	return (sibling->right);
}

template <class T1, class T2>
void do_opposite_rotation(ft::btree<T1, T2> *node_to_compare, ft::btree<T1, T2> *node_to_rotate)
{
	if (is_left_child(node_to_compare->parent, node_to_compare))
		btree_right_rotate(node_to_rotate);
	else
		btree_left_rotate(node_to_rotate);
}

template <class T1, class T2>
void do_same_side_rotation(ft::btree<T1, T2> *node_to_compare, ft::btree<T1, T2> *node_to_rotate)
{
	if (is_left_child(node_to_compare->parent, node_to_compare))
		btree_left_rotate(node_to_rotate);
	else
		btree_right_rotate(node_to_rotate);
}

template <class T1, class T2>
bool is_black_or_null(ft::btree<T1, T2> *node)
{
	if (node == NULL)
		return (true);
	if (node->color == BLACK)
		return (true);
	return (false);
}

template <class T1, class T2>
bool is_red_node(ft::btree<T1, T2> *node)
{
	return (!is_black_or_null(node));
}

template <class T1, class T2>
void	remove_double_black(ft::btree<T1, T2> *node)
{
	node->color = BLACK;
}

template <class T1, class T2>
void swap_node_color(ft::btree<T1, T2> *node1, ft::btree<T1, T2> *node2)
{
	ft::t_color tmp;

	tmp = node1->color;
	node1->color = node2->color;
	node2->color = tmp;
}

template <class T1, class T2>
void	black_sibling_case(ft::btree<T1, T2> *double_black_node)
{
	ft::btree<T1, T2> *sibling = get_sibling(double_black_node);
	ft::btree<T1, T2> *parent = double_black_node->parent;
	
	if (is_red_node(get_opposite_niece(double_black_node, sibling)))
	{
		swap_node_color(parent, sibling);
		get_opposite_niece(double_black_node, sibling)->color = BLACK;
		do_same_side_rotation(double_black_node, parent);
		remove_double_black(double_black_node);
	}
	else if (is_black_or_null(get_same_direction_niece(double_black_node, sibling)))
	{
		double_black_node->color = BLACK;
		sibling->color = RED;
		parent->color++;
		if (parent->color == DOUBLE_BLACK)
			deal_double_black(parent);
	}
	else
	{
		swap_node_color(sibling, get_same_direction_niece(double_black_node, sibling));
		do_opposite_rotation(double_black_node, sibling);
		deal_double_black(double_black_node);
	}
}

template <class T1, class T2>
void	red_sibling_case(ft::btree<T1, T2> *double_black_node)
{
	ft::btree<T1, T2> *sibling = get_sibling(double_black_node);
	ft::btree<T1, T2> *parent = double_black_node->parent;
	
	swap_node_color(parent, sibling);
	if (is_left_child(parent, double_black_node))
		btree_left_rotate(parent);
	else
		btree_right_rotate(parent);
	deal_double_black(double_black_node);
}

template <class T1, class T2>
void deal_double_black(ft::btree<T1, T2> *double_black_node)
{
	if (is_root(double_black_node))
		return (remove_double_black(double_black_node));
	if (sibling_is_red(double_black_node))
		red_sibling_case(double_black_node);
	else	
		black_sibling_case(double_black_node);
}

template <class T1, class T2>
void check_delete_rules(ft::btree<T1, T2> *node)
{
	if (node->color == RED)
		return ;
	node->item = NULL;
	node->color = DOUBLE_BLACK;
	deal_double_black(node);
}

#endif
