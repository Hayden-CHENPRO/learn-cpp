#include <iostream>

int factorial(int);

int main()
{
	int x = 5;
	std::cout << "factorial of " << x << " is : "
		<< factorial(5) << std::endl;
	
	return 0;
}

int factorial(int x)
{
	if (x == 1)
		return 1;
	else
		return x * factorial(x - 1);
}