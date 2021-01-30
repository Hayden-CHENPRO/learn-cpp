#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minCost(std::string s, std::vector<int>& cost) {
        int costs = 0;
        int flag = 0;        // 标记搜索到哪了  

        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (cost[i] <= cost[j]) {
                        costs += cost[i];
                        flag = j;
                        break;
                    }
                    else {
                        costs += cost[j];
                        flag = j;
                        continue;
                    }
                }
                else {
                    flag = j;
                    break;
                }
            }
            i = flag - 1;    // i从上次搜索到的位置开始   
        }

        return costs;
    }
};


int main() {
    //std::string s = "aaabbbabbbb";
    std::string s = "bbbb";
    //std::vector<int> cost = { 3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1 };
    std::vector<int> cost = { 5, 4, 8, 1 };

    Solution test;
    int result = test.minCost(s, cost);
    std::cout << result << std::endl;
}


/*
*   结果：执行用时：344 ms, 在所有 C++ 提交中击败了95.65%的用户内存消耗：93.6 MB, 在所有 C++ 提交中击败了32.96%的用户  
*   时间复杂度：？
*   算法思想：【贪婪】每一堆相同字母中选择代价小的删除，使总的删除成本最小  
*   存在的问题：内存消耗较高
*/