#include <iostream>
#include <vector>

int findSmallest(const std::vector<int>& a);
std::vector<int>* selectionSort(std::vector<int>& a);

int main()
{
	std::vector<int> a = { 5, 3, 6, 2, 10 };
	std::vector<int>* sorted_list = selectionSort(a);
	
	for (int i = 0; i < 5; ++i)
		std::cout << (*sorted_list)[i] << std::endl;

	delete sorted_list;			//删除分配的内存

	return 0;
}


int findSmallest(const std::vector<int>& a)
{
	int smallest = a[0];
	int smallest_idx = 0;

	for (decltype(a.size()) i = 0; i < a.size(); ++i) {
		if (smallest >= a[i]) {
			smallest = a[i];
			smallest_idx = i;
		}
	}
	return smallest_idx;
}


std::vector<int>* selectionSort(std::vector<int>& a)	
{
	std::vector<int>* sorted_list = new std::vector<int> {};		//返回数组的动态内存管理

	for (int i = 0; i < 5; ++i) {
		int smallest_idx = findSmallest(a);
		sorted_list->push_back(a[smallest_idx]);
		a.erase(a.begin()+smallest_idx);
	}
	return sorted_list;
}

