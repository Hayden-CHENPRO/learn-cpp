#include <iostream>
#include "7.1.2 Sales_data2.h"

main()
{
	Sales_data total;	//���浱ǰ��ͽ���ı���
	if (read(std::cin, total)) {
		Sales_data trans;	//������һ���������ݵı���
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

