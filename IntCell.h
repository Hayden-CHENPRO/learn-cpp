#ifndef IntCell_H
#define IntCell_H

//����������ӿ� 

class IntCell
{
	public:
		explicit IntCell(int intialValue = 0);	//�������Ĺ��캯�����������������ʽ����ת��
		int read() const;
		void write(int x);
		
	private:
		int storedValue = 0;
};

#endif
