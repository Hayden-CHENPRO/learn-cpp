#ifndef IntCell_H
#define IntCell_H

//类声明及其接口 

class IntCell
{
	public:
		explicit IntCell(int intialValue = 0);	//单参数的构造函数，避免编译器的隐式类型转换
		int read() const;
		void write(int x);
		
	private:
		int storedValue = 0;
};

#endif
