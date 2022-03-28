
#include "btree.hpp"


template<typename T>
void print_level(T* element, int current_level, int is_first)
{
	if (is_first)
		std::cout << std::endl << "level " << current_level << ": " << *element;
	else
		std::cout << " | " << *element;
}

template<typename T>
void print_level(ft::btree<T> *root, int expected)
{
	int level;
	
	level = btree_level_count<int>(root);
	std::cout << "level expected: " << expected << "\tlevel count: " << level << std::endl;
}


void	test2(void)
{
	ft::btree<int>	*root = NULL;
	
	std::cout << "insert " << 10 << std::endl;
	btree_insert_data(&root, new int(10), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 5 << std::endl;
	btree_insert_data(&root, new int(5), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 7 << std::endl;
	btree_insert_data(&root, new int(7), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 20 << std::endl;
	btree_insert_data(&root, new int(20), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 25 << std::endl;
	btree_insert_data(&root, new int(25), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 21 << std::endl;
	btree_insert_data(&root, new int(21), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 30 << std::endl;
	btree_insert_data(&root, new int(30), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 15 << std::endl;
	btree_insert_data(&root, new int(15), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	std::cout << "insert " << 12 << std::endl;
	btree_insert_data(&root, new int(12), &compare);
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---DELETE 21---\n" << std::endl;
	delete (btree_delete(&root,21));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---DELETE 15---\n" << std::endl;
	delete (btree_delete(&root,15));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---DELETE 20---\n" << std::endl;
	delete (btree_delete(&root,20));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---RIGHT ROTATE---\n" << std::endl;
	btree_right_rotate(btree_search_node(root, 07, &compare));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	std::cout << "\n---LEFT ROTATE---\n" << std::endl;
	btree_left_rotate(btree_search_node(root, 25, &compare));

	std::cout << "\n---NODE, LEVEL AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_rb_node_infos);
	
	btree_delete_tree(root);
}


int main(void)
{
	ft::btree<int> *root = NULL;
	for (int i = 10; i < 20; i++)
	{
		std::cout << "insert " << i << std::endl;
		btree_insert_data(&root, new int(i), &compare);
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "insert " << i << std::endl;
		btree_insert_data(&root, new int(i), &compare);
		btree_apply_by_level(root, print_rb_node_infos);
	}

	std::cout << "\n---INFIX---\n" << std::endl;
	btree_apply_infix(root, print_item);
	std::cout << "\n---PREFIX---\n" << std::endl;
	btree_apply_prefix(root, print_item);
	std::cout << "\n---SUFFIX---\n" << std::endl;
	btree_apply_suffix(root, print_item);

	std::cout << "\n---SEARCH---\n" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		int * number = btree_search_item(root, i, &compare);
		std::cout << *number << " " << number << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		int * number = btree_search_item(root, i, &compare);
		std::cout << *number << " " << number << std::endl;
	}
	for (int i = 99; i < 111; i++)
	{
		int * number = btree_search_item(root, i, &compare);
		if (number == NULL)
			std::cout << i << " NOT IN TREE" << std::endl;
		else
			std::cout << *number << " " << number << std::endl;
	}

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos);

	std::cout << "\n---NODE AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_node_and_parent);

	std::cout << "\n---DELETE---\n" << std::endl;
	for (int i = 10; i < 15; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 15; i < 20; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << "delete " << i << std::endl;
		delete (btree_delete(&root, i));
		btree_apply_by_level(root, print_rb_node_infos);
	}
	
//btree_delete_tree(root);
	test2();
}
