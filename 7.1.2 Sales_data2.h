#ifndef SALES_DATA_H	//注意这里要和类名相同，而不是文件名相同
#define SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data
{
	//声明友元
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

public:
	//新增的构造函数
	Sales_data() = default;		//等同于之前使用的合成默认构造函数；因为我们既需要自己定义的，又需要默认的
	Sales_data(const std::string& s, unsigned n, double p) :	//函数体内{}为空，因为没有任务要执行，只需要初始化
		bookNo(s), units_sold(n), revenue(p * n) { }		//小括号内的即为初始值
	Sales_data(std::istream& is) { read(is, *this); }

	//新成员：关于Sales_data对象的操作
	std::string isbn() const { return bookNo; }		//const使this指针变成了指向常量的指针，所以常量成员函数不能改变调用它的对象的内容，即此处isbn只能读取不能写入
	Sales_data& combine(const Sales_data&);

private:
	double avg_price() const
		{ return units_sold ? revenue/units_sold : 0; }

	//数据成员和2.6.1节（第64页）相比没有改变
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


//类外部定义成员函数
double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;	//返回调用该函数的对象
}

//在类的头文件里面，定义了就不需要再声明了，否则会报重载函数多匹配
////声明Sales_data成员接口函数，类相关的非成员函数
//Sales_data add(const Sales_data&, const Sales_data&);
//std::ostream& print(std::ostream&, const Sales_data);
//std::istream& read(std::istream, Sales_data&);


//定义外部接口函数
std::istream& read(std::istream& is, Sales_data& item)		//把item内容写入is
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}


#endif