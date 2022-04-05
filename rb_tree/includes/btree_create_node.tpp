/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:23:35 by lfrasson          #+#    #+#             */
/*   Updated: 2022/04/04 23:01:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_CREATE_NODE_TPP
#define BTREE_CREATE_NODE_TPP

#include "btree.tpp"

template <typename T>
ft::btree<T> *create_nil_node(void)
{
	return (new ft::btree<T>());
}

template <typename T>
ft::btree<T> *btree_create_node(const T *new_item)
{
	ft::btree<T> *new_node = new ft::btree<T>(new_item);
	new_node->left = create_nil_node<T>();
	new_node->right = create_nil_node<T>();
	return (new_node);
}

template <typename T>
ft::btree<T> *btree_create_root(const T *new_item)
{
	ft::btree<T> *new_node = new ft::btree<T>(new_item, BLACK);
	new_node->left = create_nil_node<T>();
	new_node->right = create_nil_node<T>();
	return (new_node);
}

#endif
