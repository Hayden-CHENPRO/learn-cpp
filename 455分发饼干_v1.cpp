#include <vector>
#include <iostream>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int> s) {
        int num = 0;                       // 最大能满足胃口的小朋友数  
        for (int i = 0; i < g.size(); i++) {
            if (s.size() != 0) {
                auto it = s.begin();
                std::vector<int>::iterator temp = it;    // 用于临时存放匹配上的尺寸的饼干  
                int flag = 0;     // 用于标记是否temp中有临时存放的小饼干（该小饼干等待判断是否为最小）  
                int flag2 = 0;    // 标记是否存在合适的小饼干；0表示不存在，1表示存在  

                while (it != s.end()) {
                    if (g[i] == *it) {      // 如果胃口和尺寸完美匹配则直接跳出  
                        temp = it;
                        flag2 = 1;
                        break;
                    }
                    else if (g[i] < *it)    // 如果胃口小于尺寸则再判断是否该尺寸为最小合适尺寸   
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
*   结果：正确，但是最后一个测试用例超出时间限制 
*   时间复杂度：g.size() * s.size()  
*   算法思想：【循环遍历】遍历所有的小朋友，再遍历所有的饼干，从所有合适的饼干中挑出尺寸最接近小朋友的胃口的  
*   存在的问题：并未很好体现贪婪二字：没有先考虑饥饿度最小的孩子最容易吃饱  
*/