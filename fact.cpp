#include "Chapter6.h"	// 要包含声明的头文件 

// 写函数主体，定义 
int fact(int val)
{
	// 计算val的阶乘 
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;	
}
 
 
 
