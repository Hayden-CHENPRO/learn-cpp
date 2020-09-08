#include <iostream>
using namespace std;

int s[3][4] = {{3}, {8}, {9}};

void print(int arr[][4]);
 
int main()
{	
	print(s);

	return 0;
}
 
void print(int arr[][4])
{
	cout << arr[1][0] << endl;
}
 
