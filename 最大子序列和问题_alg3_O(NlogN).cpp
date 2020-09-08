#include <iostream>
#include <vector>
#include <initializer_list>

int maxSumRec(const std::vector<int>& a, int left, int right);
int maxSubSum3(const std::vector<int>& a);
int max(std::initializer_list<int> lst);

int main()
{
	std::vector<int> a{ 4,-3,5,-2,-1,2,6,-2 };

	std::cout << "The max subSum is : " << maxSubSum3(a) << std::endl;

	return 0;
}

int maxSubSum3(const std::vector<int>& a)
{
	return maxSumRec(a, 0, a.size() - 1);
}

int maxSumRec(const std::vector<int>& a, int left, int right)
{
	if (left == right)
		if (a[left] > 0)
			return a[left];
		else
			return 0;

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; --i) {
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; ++j) {
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max({ maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum });
}

int max(std::initializer_list<int> lst)
{
	auto beg = lst.begin(), end = lst.end();
	int maxNum = *beg;

	for (beg; beg != end; ++beg) {
		if (*beg > maxNum)
			maxNum = *beg;
	}

	return maxNum;
}