#include <iostream>
#include <vector>

class Solution {
public:
	std::vector <int> twoSum(std::vector <int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] + nums[j] == target) {
					return { i, j };
				}
			}
		}
		return {};
	}
};

int main() {
	std::vector <int> arr = {2, 7, 11, 15};
	int val = 9;
	Solution test;
	std::vector <int> result = test.twoSum(arr, val);
	std::cout << "[" << result[0] << "," << result[1] << "]" << std::endl;
	return 0;
}