#include <iostream>

int Fcn(int x,int low = 1,int high = 100)
{
	if (x < low) return low;
	else if (x > high) return high;
	else
		return x;
}

double Fcn(double x, double low = 1.0, double high = 100.0)
{
	if (x < low) return low;
	else if (x > high) return high;
	else
		return x;
}

int main()
{
	int x{ 10 };
	double y{ 2.5 };
	std::cout << Fcn(x) << '\n';
	std::cout << Fcn(y) << '\n';

	return 0;
}