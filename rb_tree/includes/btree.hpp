
#ifndef TREE_HPP
#define TREE_HPP

# define CYAN			"\e[0;36m"
# define C_RED			"\e[0;31m"
# define RESET			"\e[0m"
# define BOLD			"\e[1m"

#include <iostream>
#include "btree.tpp"

#include "compare.tpp"
#include "print_item.tpp"

#include "btree_right_rotate.tpp"
#include "btree_left_rotate.tpp"

#include "btree_insert_data.tpp"
#include "btree_search_item.tpp"
#include "btree_delete_tree.tpp"
#include "btree_delete.tpp"

#include "btree_level_count.tpp"

#include "btree_apply_prefix.tpp"
#include "btree_apply_infix.tpp"
#include "btree_apply_suffix.tpp"
#include "btree_apply_by_level.tpp"

#endif
