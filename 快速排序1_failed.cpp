#include <iostream>
#include <vector>

std::vector<int>* quickSort(std::vector<int>&);

int main()
{
	std::vector<int> a = { 5, 3, 6, 2 };
	std::vector<int>* vec = quickSort(a);

	for (decltype(a.size()) i = 0; i < a.size(); ++i) {
		std::cout << (*vec)[i] << "  ";
	}
	std::cout << std::endl;

	delete vec;

	return 0;
}

std::vector<int>* quickSort(std::vector<int>& a)
{
	std::vector<int>* vec = new std::vector<int>(a);

	if (a.size() < 2)
		return vec;
	else {
		int pivot = (*vec)[0];
		std::vector<int> less, greater;

		for (auto it = (*vec).begin(); it != (*vec).end(); ++it) {
			if (*it < pivot)
				less.push_back(*it);
			else if (*it > pivot)
				greater.push_back(*it);
		}

		quickSort(less)->push_back(pivot);
		std::cout << "!!" << std::endl;
		quickSort(greater);
		std::cout << "-----" << std::endl;
		less.insert(less.end(), greater.begin(), greater.end());
		return &less;
	}

}




