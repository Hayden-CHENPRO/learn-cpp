#include <iostream>
#include "IntCell.h"

//��������ʹ��IntCell��

using namespace std;

int main()
{
	IntCell m;
	
	m.write(5);
	cout << "Cell contents: " << m.read() << endl;
	
	return 0;
 } 
 

//int main()
//{
//	IntCell* m;
//
//	m = new IntCell;
//	m->write(5);
//	cout << "Cell contents: " << m->read() << endl;
//
//	delete m;
//	return 0;
//}