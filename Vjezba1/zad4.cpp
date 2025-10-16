#include <iostream>

int &at(int arr[], int index)
{
	return arr[index];
}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int i = 3;
	at(arr, i)++;

	for (int x : arr)
		std::cout << x << ' ';

	return 0;
}