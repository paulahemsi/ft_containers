
#ifndef COMPARE_TPP
#define COMPARE_TPP

template <typename T>
bool compare(T item1, T item2)
{
	if (*item1 > *item2)
		return true;
	return false;
}

#endif
