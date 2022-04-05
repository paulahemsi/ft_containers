/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:23:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/05 11:32:53 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_CREATE_NODE_TPP
#define BTREE_CREATE_NODE_TPP

#include "btree.tpp"

template <typename T>
ft::btree<T> *create_nil_node(ft::btree<T> *parent)
{
	ft::btree<T> *nil_node = new ft::btree<T>();
	nil_node->parent = parent;
	return (nil_node);
}

template <typename T>
ft::btree<T> *btree_create_node(const T *new_item)
{
	ft::btree<T> *new_node = new ft::btree<T>(new_item);
	new_node->left = create_nil_node(new_node);
	new_node->right = create_nil_node(new_node);
	return (new_node);
}

template <typename T>
ft::btree<T> *btree_create_root(const T *new_item)
{
	ft::btree<T> *new_node = new ft::btree<T>(new_item, BLACK);
	new_node->left = create_nil_node(new_node);
	new_node->right = create_nil_node(new_node);
	return (new_node);
}

#endif
