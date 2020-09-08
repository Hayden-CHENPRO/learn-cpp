#include <iostream>
#include "7.1.2 Sales_data2.h"

main()
{
	Sales_data total;	//保存当前求和结果的变量
	if (read(std::cin, total)) {
		Sales_data trans;	//保存下一条交易数据的变量
		while (read(std::cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
	}
}

