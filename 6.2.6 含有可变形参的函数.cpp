#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

void error_msg(initializer_list<string> il);

int main()
{
	string expected, actual;
	cin >> expected >> actual;

	if (expected != actual)
		error_msg({ "functionX", expected, actual });
	else
		error_msg({ "functionX", "okey" });
}

void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}