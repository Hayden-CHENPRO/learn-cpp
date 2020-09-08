#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string; 

int main()
{	
	std::vector<string> text{"some string", "", "asdasd"};
	
	for (auto it = text.cbegin();
		it != text.cend() && !it->empty(); ++it)	// asdasd不会被打印 
		cout << *it << endl;
	
}
 
 
 
