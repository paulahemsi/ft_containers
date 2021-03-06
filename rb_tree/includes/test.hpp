
#ifndef TREE_HPP
#define TREE_HPP

# define CYAN			"\e[0;36m"
# define C_RED			"\e[0;31m"
# define RESET			"\e[0m"
# define BOLD			"\e[1m"

#include <iostream>

#include "pair.tpp"
#include "print_item.tpp"

#include "btree_insert_data.tpp"
#include "btree_search_item.tpp"
#include "btree_delete.tpp"

#include "btree_level_count.tpp"

#include "btree_apply_prefix.tpp"
#include "btree_apply_infix.tpp"
#include "btree_apply_suffix.tpp"
#include "btree_apply_by_level.tpp"

#include "btree_begin.tpp"
#include "btree_end.tpp"
#include "btree_next.tpp"
#include "btree_previous.tpp"

#endif
