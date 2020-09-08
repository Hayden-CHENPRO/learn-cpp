#include <iostream>

int maxSide_of_square(int, int);

// À„∑®ÕºΩ‚P42
int main()
{
	int length = 1680, width = 640;
	int square_max_side_length = maxSide_of_square(length, width);

	std::cout << "The max square's side length is : " << square_max_side_length << std::endl;

	return 0;
}

int maxSide_of_square(int length, int width)
{
	int side = length - width * (length / width);

	if (side == 0) 
		return width;
	else {
		length = width;
		width = side;
		return maxSide_of_square(length, width);
	}
}