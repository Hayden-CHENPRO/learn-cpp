#include <iostream>
#include <vector>

//int binarySearch(const std::vector<T>& a, const T& x);

template <typename T>
int binarySearch(const std::vector<T>& a, const T& x)
{
	int low = 0, high = a.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (a[mid] > x)
			low = mid + 1;
		else if (a[mid] < x)
			high = mid - 1;
		else
			return mid;
	}

	return -1;
}


int main()
{
	std::vector<int> a{ 64, 32, 16, 8, 4, 2, 1, 0, -1 };
	std::cout << "i is : " << binarySearch(a, 16) << std::endl;

	return 0;
}