#include <vector>
#include <iostream>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int> s) {
        int num = 0;                       // ���������θ�ڵ�С������  
        for (int i = 0; i < g.size(); i++) {
            if (s.size() != 0) {
                auto it = s.begin();
                std::vector<int>::iterator temp = it;    // ������ʱ���ƥ���ϵĳߴ�ı���  
                int flag = 0;     // ���ڱ���Ƿ�temp������ʱ��ŵ�С���ɣ���С���ɵȴ��ж��Ƿ�Ϊ��С��  
                int flag2 = 0;    // ����Ƿ���ں��ʵ�С���ɣ�0��ʾ�����ڣ�1��ʾ����  

                while (it != s.end()) {
                    if (g[i] == *it) {      // ���θ�ںͳߴ�����ƥ����ֱ������  
                        temp = it;
                        flag2 = 1;
                        break;
                    }
                    else if (g[i] < *it)    // ���θ��С�ڳߴ������ж��Ƿ�óߴ�Ϊ��С���ʳߴ�   
                    {
                        flag2 = 1;
                        if (flag == 0) {
                            flag++;
                            temp = it;
                            it++;
                            continue;
                        }
                        else {
                            if (*it < *temp)
                                temp = it;
                            it++;
                            continue;
                        }
                    }
                    else
                        it++;
                }
                if (flag2 == 1) {
                    temp = s.erase(temp);
                    num++;
                }
            }
        }
        return num;
    }
};

int main() {
    std::vector <int> g = { 1, 2, 3 };
    std::vector <int> s = { 3, 1 };
    Solution test;
    int result = test.findContentChildren(g, s);
    std::cout << result << std::endl;
}


/*
*   �������ȷ���������һ��������������ʱ������ 
*   ʱ�临�Ӷȣ�g.size() * s.size()  
*   �㷨˼�룺��ѭ���������������е�С���ѣ��ٱ������еı��ɣ������к��ʵı����������ߴ���ӽ�С���ѵ�θ�ڵ�  
*   ���ڵ����⣺��δ�ܺ�����̰�����֣�û���ȿ��Ǽ�������С�ĺ��������׳Ա�  
*/