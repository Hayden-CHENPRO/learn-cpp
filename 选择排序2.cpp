#include <iostream>
#include <iterator>

int* selectionSort(int [], size_t);

int main()
{
	int a[] = { 5, 3, 6, 2, 10 };
	size_t size = sizeof(a) / sizeof(a[0]);
	selectionSort(a, size);
	int* beg = std::begin(a), * last = std::end(a);

	for (beg; beg != last; ++beg) {
		std::cout << *beg << "  " ;
	}
	std::cout << std::endl;

	return 0;
}

int* selectionSort(int a[], size_t size)
{
	int smallest = a[0];
	int smallest_idx = 0;
	int temp = 0;

	for (size_t i = 0; i < size; ++i) {
		smallest = a[i];
		smallest_idx = i;

		for (size_t j = i; j < size; ++j) {
			if (smallest > a[j]) {
				smallest = a[j];
				smallest_idx = j;
			}
		}

		temp = a[smallest_idx];
		a[smallest_idx] = a[i];
		a[i] = temp;
	}

	return a;
}