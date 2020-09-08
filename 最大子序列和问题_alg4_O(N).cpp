#include <iostream>
#include <vector>

int maxSubSum4(std::vector<int> a);

int main()
{
		std::vector<int> a{ 4,-3,5,-2,-1,2,6,-2 };

		std::cout << "The max subSum is : " << maxSubSum4(a) << std::endl;

		return 0;
}

int maxSubSum4(std::vector<int> a)
{
	int maxSum = 0, thisSum = 0;
	for (int j = 0; j < a.size(); ++j) {
		thisSum += a[j];

		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum <= 0)
			maxSum = 0;
	}

	return maxSum;
}