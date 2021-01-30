#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int num = 0;                       // ���������θ�ڵ�С������  
        int temp = 0;                      // ���ڱ���ϴαȶԵ���С���ɵ�λ��   
        std::sort(g.begin(), g.end());     // Ĭ������  
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
*   �����ִ����ʱ��80 ms, ������ C++ �ύ�л�����92.60%���û��ڴ����ģ�17.5 MB, ������ C++ �ύ�л�����5.43%���û� 
*   ʱ�临�Ӷȣ�n*log2(n) + n*log2(n) + i + j
*   �㷨˼�룺��̰������ʣ�ຢ������С�����ȵĺ��ӷ�����С���ܱ����ı���  
*   ���ڵ����⣺�ڴ����Ľϸ� 
*/