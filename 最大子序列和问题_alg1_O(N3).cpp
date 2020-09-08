#include <iostream>
#include <vector>

int maxSubSum2(const std::vector<int>& a);

int main()
{
	std::vector<int> v{ -2, 11, -4, 13, -5, -2 };
	std::cout << "The max subSum is : " << maxSubSum2(v) << std::endl;

	return 0;
}

int maxSubSum2(const std::vector<int>& a)
{
	int maxSubSum = 0;

	for (int i = 0; i < a.size(); ++i) {
		for (int j = i; j < a.size(); ++j) {
			int subSum = 0;

			for (int k = i; k < j; ++k) {
				subSum += a[k];

			if (subSum > maxSubSum)
				maxSubSum = subSum;
			}
		}
	}

	return maxSubSum;
}