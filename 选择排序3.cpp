#include <iostream>
#include <vector>

std::vector<int>* selectionSort(std::vector<int>& a);

int main()
{
	std::vector<int> a = { 5, 3, 6, 2, 10 };
	std::vector<int>* vec = selectionSort(a);

	for (int i = 0; i < a.size(); ++i) {
		std::cout << (*vec)[i] << "  ";
	}
	std::cout << std::endl;

	delete vec;
	return 0;
}

std::vector<int>* selectionSort(std::vector<int>& a)		//返回的是指针
{
	//std::vector<int>* a = new std::vector<int> (a);
	std::vector<int>* vec = new std::vector<int>(a);
	int smallest = (*vec)[0];
	int smallest_idx = 0;
	int temp;

	for (int i = 0; i < (*vec).size(); ++i) {
		smallest = (*vec)[i];
		smallest_idx = i;

		for (int j = i; j < (*vec).size(); ++j) {
			if (smallest > (*vec)[j]) {
				smallest = (*vec)[j];
				smallest_idx = j;
			}
		}

		temp = (*vec)[smallest_idx];
		(*vec)[smallest_idx] = (*vec)[i];
		(*vec)[i] = temp;
	}

	return vec;
}