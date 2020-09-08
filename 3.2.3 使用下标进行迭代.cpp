#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string; 

int main()
{	
	string s("some string");
	
	for (decltype(s.size()) index = 0; 
		index != s.size() && !isspace(s[index]); index++){
			s[index] = toupper(s[index]);
			cout << (index != s.size() && !isspace(s[index]));
		}
	
	cout << '\n' << s << endl;
	
}
 
 
 
