
#ifndef COMPARE_TPP
#define COMPARE_TPP

template <typename T>
bool compare(const T &item1, const T &item2)
{
	if (item1 > item2)
		return true;
	return false;
}

#endif
