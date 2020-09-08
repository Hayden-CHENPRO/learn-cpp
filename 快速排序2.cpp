#include <iostream>
#include <vector>

void quickSort(int left, int right, std::vector<int>& arr);

int main()
{
	std::vector<int> arr = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	quickSort(0, arr.size() - 1, arr);

	for (decltype(arr.size()) i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;

	return 0;
}

void quickSort(int left, int right, std::vector<int>& arr)
{
	if (left >= right)
		return;

	int i, j, base, temp;
	i = left; j = right;
	base = arr[left];

	while (i < j) {
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	//»ù×¼Êý¹éÎ»
	arr[left] = arr[i];
	arr[i] = base;

	quickSort(left, i - 1, arr);//µÝ¹é×ó±ß
	quickSort(i + 1, right, arr);//µÝ¹éÓÒ±ß
}