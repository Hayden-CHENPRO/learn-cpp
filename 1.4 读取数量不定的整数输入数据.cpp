#include <iostream>

int main()
{	
	int sum = 0, value = 0;
	//读取数据直到遇到文件尾，计算所有读入数值的和，遇到文件结束符停止循环 
	while (std::cin >> value)
		sum += value; 
	std::cout << "Sum is: " << sum << std::endl;
	
	return 0; 
}
 
 
 
