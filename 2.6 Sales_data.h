#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;   // todo ��ϰһ��ɶʱ����unsigned �� P32 
	double revenur = 0.0; 
}; 
Sales_data accun, trans, *salesptr; 
#endif
