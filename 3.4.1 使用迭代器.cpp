#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string; 

int main()
{	
	std::vector<string> text{"some string", "", "asdasd"};
	
	for (auto it = text.cbegin();
		it != text.cend() && !it->empty(); ++it)	// asdasd���ᱻ��ӡ 
		cout << *it << endl;
	
}
 
 
 
