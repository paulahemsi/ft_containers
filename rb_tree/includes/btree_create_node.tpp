/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:23:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/22 16:00:38 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_CREATE_NODE_TPP
#define BTREE_CREATE_NODE_TPP

#include "btree.tpp"

template <typename T, class Alloc>
ft::btree<T> *create_nil_node(ft::btree<T> *parent, Alloc alloc)
{
	ft::btree<T> *nil_node = alloc.allocate(1);
	alloc.construct(nil_node, ft::btree<T>());
	nil_node->parent = parent;
	return (nil_node);
}

template <typename T, class Alloc>
ft::btree<T> *btree_create_node(T *new_item, Alloc alloc)
{
	ft::btree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::btree<T>(new_item));
	new_node->left = create_nil_node(new_node, alloc);
	new_node->right = create_nil_node(new_node, alloc);
	return (new_node);
}

template <typename T, class Alloc>
ft::btree<T> *btree_create_root(T *new_item, Alloc alloc)
{
	ft::btree<T> *new_node = alloc.allocate(1);
	alloc.construct(new_node, ft::btree<T>(new_item, BLACK));
	new_node->left = create_nil_node(new_node, alloc);
	new_node->right = create_nil_node(new_node, alloc);
	return (new_node);
}

#endif
