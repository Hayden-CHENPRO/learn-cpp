#ifndef SALES_DATA_H	//ע������Ҫ��������ͬ���������ļ�����ͬ
#define SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data
{
	//������Ԫ
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

public:
	//�����Ĺ��캯��
	Sales_data() = default;		//��ͬ��֮ǰʹ�õĺϳ�Ĭ�Ϲ��캯������Ϊ���Ǽ���Ҫ�Լ�����ģ�����ҪĬ�ϵ�
	Sales_data(const std::string& s, unsigned n, double p) :	//��������{}Ϊ�գ���Ϊû������Ҫִ�У�ֻ��Ҫ��ʼ��
		bookNo(s), units_sold(n), revenue(p * n) { }		//С�����ڵļ�Ϊ��ʼֵ
	Sales_data(std::istream& is) { read(is, *this); }

	//�³�Ա������Sales_data����Ĳ���
	std::string isbn() const { return bookNo; }		//constʹthisָ������ָ������ָ�룬���Գ�����Ա�������ܸı�������Ķ�������ݣ����˴�isbnֻ�ܶ�ȡ����д��
	Sales_data& combine(const Sales_data&);

private:
	double avg_price() const
		{ return units_sold ? revenue/units_sold : 0; }

	//���ݳ�Ա��2.6.1�ڣ���64ҳ�����û�иı�
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


//���ⲿ�����Ա����
double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;	//���ص��øú����Ķ���
}

//�����ͷ�ļ����棬�����˾Ͳ���Ҫ�������ˣ�����ᱨ���غ�����ƥ��
////����Sales_data��Ա�ӿں���������صķǳ�Ա����
//Sales_data add(const Sales_data&, const Sales_data&);
//std::ostream& print(std::ostream&, const Sales_data);
//std::istream& read(std::istream, Sales_data&);


//�����ⲿ�ӿں���
std::istream& read(std::istream& is, Sales_data& item)		//��item����д��is
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