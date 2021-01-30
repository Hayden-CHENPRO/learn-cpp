#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int num = 0;                       // 最大能满足胃口的小朋友数  
        int temp = 0;                      // 用于标记上次比对到的小饼干的位置   
        std::sort(g.begin(), g.end());     // 默认升序  
        std::sort(s.begin(), s.end());

        for (int i = 0; i < g.size(); i++) {
            for (int j = temp; j < s.size(); j++) {
                if (g[i] <= s[j]) {
                    temp = j + 1;
                    num++;
                    break;
                }
            }
        }

        return num;
    }
};


int main() {
    std::vector <int> g = { 1, 2, 3 };
    std::vector <int> s = { 1, 3 };

    Solution test;
    int result = test.findContentChildren(g, s);
    std::cout << result << std::endl;
}


/*
*   结果：执行用时：80 ms, 在所有 C++ 提交中击败了92.60%的用户内存消耗：17.5 MB, 在所有 C++ 提交中击败了5.43%的用户 
*   时间复杂度：n*log2(n) + n*log2(n) + i + j
*   算法思想：【贪婪】给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干  
*   存在的问题：内存消耗较高 
*/