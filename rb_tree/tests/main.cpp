
#include "btree.tpp"
#include "test.hpp"

template< class T>
void print_level(T* pair, int current_level, int is_first)
{
	if (is_first)
		std::cout << std::endl << "level " << current_level << ": " << "key: " << *pair->first;
	else
		std::cout << " | " << "key: " << *pair->first;
}

template< class T>
void print_level(ft::btree<T> *root, int expected)
{
	int level;
	
	level = btree_level_count<T>(root);
	std::cout << "level expected: " << expected << "\tlevel count: " << level << std::endl;
}

template< class T>
const ft::btree<T> * print_begin(ft::btree<T> *root)
{
	std::cout << "\n---BEGIN---\n" << std::endl;
	const ft::btree<ft::pair<int, int> >	*begin = btree_begin(root);
	if (begin)
	{
		std::cout << "key: " << begin->item->first << " value: " << begin->item->second << " " << std::endl;
		return (begin);
	}
	std::cout << "sorry, there's no tree :( " << std::endl;
	return (NULL);
}

template< class T>
const ft::btree<T> * print_end(ft::btree<T> *root)
{
	std::cout << "\n---END---\n" << std::endl;
	const ft::btree<ft::pair<int, int> >	*end = btree_end(root);
	// if (end)
	// {
	// 	std::cout << "key: " << end->item->first << " value: " << end->item->second << " " << std::endl  << std::endl;
		return (end);
	// }
	// std::cout << "sorry, there's no tree :( " << std::endl;
	// return (NULL);
}

template< class T>
void print_next(const ft::btree<T> *root)
{
	std::cout << "\n---NEXT---\n" << std::endl;
	const ft::btree<ft::pair<int, int> >	*next = btree_next(root);
	if (next && !is_nil(next))
		std::cout << "key: " << next->item->first << " value: " << next->item->second << " " << std::endl;
	else
		std::cout << "sorry, there's no next :( " << std::endl;
}

template< class T>
void print_previous(const ft::btree<T> *root)
{
	std::cout << "\n---PREVIOUS---\n" << std::endl;
	const ft::btree<ft::pair<int, int> >	*previous = btree_previous(root);
	if (previous && !is_nil(previous))
		std::cout << "key: " << previous->item->first << " value: " << previous->item->second << " " << std::endl;
	else
		std::cout << "sorry, there's no previous :( " << std::endl;
}

template< class T>
class value_compare
{
	friend class map;

	public:
	std::less<int> comp;
	value_compare (void) : comp(std::less<int>()) {}

	bool operator() (const T& x, const T& y) const
	{
		return comp(x.first, y.first);
	}
};

int main(void)
{
	value_compare<ft::pair<int, int> > compare;
	std::allocator< ft::btree<ft::pair<int, int> > > node_alloc;

	ft::btree<ft::pair<int, int> > *root = NULL;
	for (int i = 10; i < 20; i++)
	{
		std::cout << "insert " << i << std::endl;
		ft::pair<int, int> * my_pair1 = new ft::pair<int, int>(i, i);
		btree_insert_data(&root, my_pair1, compare, node_alloc);
		btree_apply_by_level(root, print_rb_node_infos, node_alloc);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << "insert " << i << std::endl;
		ft::pair<int, int> * my_pair2 = new ft::pair<int, int>(i, i);
		btree_insert_data(&root, my_pair2, compare, node_alloc);
		btree_apply_by_level(root, print_rb_node_infos, node_alloc);
	}
	print_next(print_begin(root));
	print_previous(print_end(root));
	
	std::cout << "\n---SEARCH---\n" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		const ft::pair<int, int>	*pair = btree_search_item(root, ft::pair<int, int>(i, i), compare);
		std::cout << "key: " << pair->first << "value: " << pair->second << " " << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		const ft::pair<int, int>	*pair = btree_search_item(root, ft::pair<int, int>(i, i), compare);
		std::cout << "key: " << pair->first << "value: " << pair->second << " " << std::endl;
	}
	for (int i = 99; i < 111; i++)
	{
		const ft::pair<int, int>	*pair = btree_search_item(root, ft::pair<int, int>(i, i), compare);
		if (pair == NULL)
			std::cout << i << " NOT IN TREE" << std::endl;
		else
			std::cout << "key: " << pair->first << "value: " << pair->second << " " << std::endl;
	}

	std::cout << "\n---TREE BY LEVEL---\n" << std::endl;
	btree_apply_by_level(root, print_node_infos, node_alloc);

	std::cout << "\n---NODE AND PARENT---\n" << std::endl;
	btree_apply_by_level(root, print_node_and_parent, node_alloc);

	std::cout << "\n---DELETE---\n" << std::endl;
	for (int i = 10; i < 15; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, ft::pair<int, int>(i, i), compare, node_alloc));
		btree_apply_by_level(root, print_rb_node_infos, node_alloc);

		print_next(print_begin(root));
		print_previous(print_end(root));

	}
	for (int i = 15; i < 20; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, ft::pair<int, int>(i, i), compare, node_alloc));
		btree_apply_by_level(root, print_rb_node_infos, node_alloc);
	
		print_next(print_begin(root));
		print_previous(print_end(root));

	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, ft::pair<int, int>(i, i), compare, node_alloc));
		btree_apply_by_level(root, print_rb_node_infos, node_alloc);
	
		print_next(print_begin(root));
		print_previous(print_end(root));

	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << CYAN << "delete " << i << RESET << std::endl;
		delete (btree_delete(&root, ft::pair<int, int>(i, i), compare, node_alloc));
		btree_apply_by_level(root, print_rb_node_infos, node_alloc);
	
		print_next(print_begin(root));
		print_previous(print_end(root));
	}

}
