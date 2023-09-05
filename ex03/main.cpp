#include "Point.hpp"

int main(int argc, char **args){
	if (argc != 1)
	{
		std::cout << "This program doesn't need arguments" << std::endl;
		return (0);
	}
	(void)args;


	bool result;

	// IF POINT IS INSIDE

	Point x(0, 0);
	Point y(3, 0);
	Point z(2, 3);
	Point pt(2, 1);

	result = bsp(x, y, z, pt);
	std::cout << result << std::endl;


	// IF POINT IS OUTSIDE

	Point a(0, 0);
	Point b(3, 0);
	Point c(2, 3);
	Point pt2(4, 4);

	result = bsp(a, b, c, pt2);
	std::cout << result << std::endl;
}