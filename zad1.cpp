#include <iostream>

int *fun(int n)
{;
	int *arr = new int[n] {1, 1};

	for (int i = 2; i < n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	return arr;
}

int main()
{
	int n{ 5 };

	int *rez = fun(n);

	for (int i = 0; i < n; i++)
		std::cout << rez[i] << ' ';

	delete[] rez;
	rez = nullptr;

	return 0;
}