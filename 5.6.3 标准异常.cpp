#include <iostream>
#include <exception>	//��Ҫ�ģ����� 
using namespace std;
 
int main()
{	
	int a, b, c;
	while (cin >> a >> b){
		try{
			c = a + b;
			cout << c << endl;
			throw exception();	//exception()���治���в��� �� 
		}
		catch (exception err){
			cout << err.what() << endl;
			break;
		}
	}	
}
 
 
 
