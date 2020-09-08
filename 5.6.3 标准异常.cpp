#include <iostream>
#include <exception>	//必要的！！！ 
using namespace std;
 
int main()
{	
	int a, b, c;
	while (cin >> a >> b){
		try{
			c = a + b;
			cout << c << endl;
			throw exception();	//exception()里面不能有参数 ！ 
		}
		catch (exception err){
			cout << err.what() << endl;
			break;
		}
	}	
}
 
 
 
