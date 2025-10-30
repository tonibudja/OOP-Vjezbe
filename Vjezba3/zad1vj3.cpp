#include <iostream>
#include <cstddef>

void sortt(int arr[], std::size_t n, bool (*cmp)(int, int))
{
	for (std::size_t i = 0; i < n; i++)
	{
		for (std::size_t j = i + 1; j < n; j++)
		{
			if (!cmp(arr[i], arr[j]))
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

inline bool uzlazno(int a,int b)
{
	return a < b;
}

inline bool silazno(int a,int b)
{
	return a > b;
}

int main()
{
	int arr[] = {5,2,9,1,3,4};
	std::size_t n = sizeof(arr) / sizeof(arr[0]);

	sortt(arr,n,uzlazno);

	for (std::size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';

	std::cout << '\n';

	sortt(arr,n,silazno);

	for (std::size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';

	return 0;
}