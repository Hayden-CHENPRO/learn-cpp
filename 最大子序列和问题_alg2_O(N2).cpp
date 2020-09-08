#include <iostream>
#include <vector>

int maxSubSum1(const std::vector<int>& a);

int main()
{
	std::vector<int> v{ -2, 11, -4,13, -5, -2 };
	std::cout << "The max SubSum is : " << maxSubSum1(v) << std::endl;

	return 0;
}

int maxSubSum1(const std::vector<int>& a)
{
	int maxSubSum = 0;

	for (int i = 1; i < a.size(); ++i) {
		int subSum = 0;

		for (int j = i; j < a.size(); ++j){
			subSum += a[j];

			if (subSum > maxSubSum)
				maxSubSum = subSum;
		}
	}

	return maxSubSum;
}