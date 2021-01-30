#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minCost(std::string s, std::vector<int>& cost) {
        int costs = 0;
        int flag = 0;        // �������������  

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
            i = flag - 1;    // i���ϴ���������λ�ÿ�ʼ   
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
*   �����ִ����ʱ��344 ms, ������ C++ �ύ�л�����95.65%���û��ڴ����ģ�93.6 MB, ������ C++ �ύ�л�����32.96%���û�  
*   ʱ�临�Ӷȣ���
*   �㷨˼�룺��̰����ÿһ����ͬ��ĸ��ѡ�����С��ɾ����ʹ�ܵ�ɾ���ɱ���С  
*   ���ڵ����⣺�ڴ����Ľϸ�
*/