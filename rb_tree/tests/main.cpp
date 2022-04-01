
#include "btree.hpp"


template< class T1, class T2 >
void print_level(ft::pair<T1, T2>* pair, int current_level, int is_first)
{
	if (is_first)
		std::cout << std::endl << "level " << current_level << ": " << "key: " << *pair->first;
	else
		std::cout << " | " << "key: " << *pair->first;
}

template< class T1, class T2 >
void print_level(ft::btree<T1, T2> *root, int expected)
{
	int level;
	
	level = btree_level_count<T1, T2>(root);
	std::cout << "level expected: " << expected << "\tlevel count: " << level << std::endl;
}

template< class T1, class T2 >
const ft::btree<T1, T2> * print_begin(ft::btree<T1, T2> *root)
{
	std::cout << "\n---BEGIN---\n" << std::endl;
	const ft::btree<int, int>	*begin = btree_begin(root);
	if (begin)
	{
		std::cout << "key: " << begin->item->first << " value: " << begin->item->second << " " << std::endl;
		return (begin);
	}
	std::cout << "sorry, there's no tree :( " << std::endl;
	return (NULL);
}

template< class T1, class T2 >
void print_next(const ft::btree<T1, T2> *root)
{
	std::cout << "\n---NEXT---\n" << std::endl;
	const ft::btree<int, int>	*next = btree_next(root);
	if (next)
		std::cout << "key: " << next->item->first << " value: " << next->item->second << " " << std::endl;
	else
		std::cout << "sorry, there's no next :( " << std::endl;
}

template< class T1, class T2 >
void print_end(ft::btree<T1, T2> *root)
{
	std::cout << "\n---END---\n" << std::endl;
	const ft::btree<int, int>	*end = btree_end(root);
	if (end)
		std::cout << "key: " << end->item->first << " value: " << end->item->second << " " << std::endl  << std::endl;
	else
		std::cout << "sorry, there's no tree :( " << std::endl;
}

// void	test2(void)
// {
// 	ft::btree<int, int>	*root = NULL;
	
// 	std::cout << "insert " << 10 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(10, 10), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 5 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(5, 5), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 7 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(7, 7), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 20 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(20, 20), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 25 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(25, 25), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 21 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(21, 21), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 30 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(30, 30), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 15 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(15, 15), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
// 	std::cout << "insert " << 12 << std::endl;
// 	btree_insert_data(&root, &ft::make_pair(12, 12), &compare);
// 	btree_apply_by_level(root, print_rb_node_infos);
	
// 	std::cout << "\n---DELETE 21---\n" << std::endl;
// 	delete (btree_delete(&root,21));

// 	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
// 	btree_apply_by_level(root, print_rb_node_infos);
	
// 	std::cout << "\n---DELETE 15---\n" << std::endl;
// 	delete (btree_delete(&root,15));

// 	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
// 	btree_apply_by_level(root, print_rb_node_infos);
	
// 	std::cout << "\n---DELETE 20---\n" << std::endl;
// 	delete (btree_delete(&root,20));

// 	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
// 	btree_apply_by_level(root, print_rb_node_infos);
	
// 	std::cout << "\n---RIGHT ROTATE---\n" << std::endl;
// 	btree_right_rotate(btree_search_node(root, 07, &compare));

// 	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
// 	btree_apply_by_level(root, print_rb_node_infos);
	
// 	std::cout << "\n---LEFT ROTATE---\n" << std::endl;
// 	btree_left_rotate(btree_search_node(root, 25, &compare));

// 	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
// 	btree_apply_by_level(root, print_rb_node_infos);
	
// 	btree_delete_tree(root);
// }


int main(void)
{
	ft::btree<int, int> *root = NULL;
	for (int i = 10; i < 20; i++)
	{
		std::cout << "insert " << i << std::endl;
		ft::pair<int, int> * my_pair1 = new ft::pair<int, int>(i, i);
		btree_insert_data<int, int, std::less<int> >(&root, my_pair1);
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "insert " << i << std::endl;
		ft::pair<int, int> * my_pair2 = new ft::pair<int, int>(i, i);
		btree_insert_data<int, int, std::less<int> >(&root, my_pair2);
		btree_apply_by_level(root, print_rb_node_infos);
	}
	print_next(print_begin(root));
	print_end(root);
	
	// std::cout << "\n---INFIX---\n" << std::endl;
	// btree_apply_infix(root, print_item);
	// std::cout << "\n---PREFIX---\n" << std::endl;
	// btree_apply_prefix(root, print_item);
	// std::cout << "\n---SUFFIX---\n" << std::endl;
	// btree_apply_suffix(root, print_item);

	std::cout << "\n---SEARCH---\n" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		const ft::pair<int, int>	*pair = btree_search_item<int, int, std::less<int> >(root, i);
		std::cout << "key: " << pair->first << "value: " << pair->second << " " << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		const ft::pair<int, int>	*pair = btree_search_item<int, int, std::less<int> >(root, i);
		std::cout << "key: " << pair->first << "value: " << pair->second << " " << std::endl;
	}
	for (int i = 99; i < 111; i++)
	{
		const ft::pair<int, int>	*pair = btree_search_item<int, int, std::less<int> >(root, i);
		if (pair == NULL)
			std::cout << i << " NOT IN TREE" << std::endl;
		else
			std::cout << "key: " << pair->first << "value: " << pair->second << " " << std::endl;
	}

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos);

	std::cout << "\n---NODE AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_node_and_parent);

	std::cout << "\n---DELETE---\n" << std::endl;
	for (int i = 10; i < 15; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);

		print_next(print_begin(root));
		print_end(root);

	}
	for (int i = 15; i < 20; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	
		print_next(print_begin(root));
		print_end(root);

	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	
		print_next(print_begin(root));
		print_end(root);

	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	
		print_next(print_begin(root));
		print_end(root);
	}
	
//btree_delete_tree(root);
	// test2();
}
