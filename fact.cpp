#include "Chapter6.h"	// Ҫ����������ͷ�ļ� 

// д�������壬���� 
int fact(int val)
{
	// ����val�Ľ׳� 
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;	
}
 
 
 
