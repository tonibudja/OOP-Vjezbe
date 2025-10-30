#include <iostream>
#include <cstddef>

inline bool uzlaznoDouble(double a, double b) { return a < b; }

inline bool silaznoDouble(double a, double b) { return a > b; }

inline bool uzlazno(int a, int b) { return a < b; }

inline bool silazno(int a, int b) { return a > b; }



template <typename T>
void sortt(T arr[], std::size_t n, bool (*cmp)(T, T))
{
	for (std::size_t i = 0; i < n - 1; i++)
	{
		for (std::size_t j = i + 1; j < n; j++)
		{
			if (!cmp(arr[i], arr[j]))
			{
				T tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


int main()
{
	int arr[] = { 5,2,9,1,3,4 };
	int arrDouble[] = { 2.1,3.5,7.2,0.3,1.1 };

	std::size_t n = sizeof(arr) / sizeof(arr[0]);
	std::size_t nd = sizeof(arrDouble) / sizeof(arrDouble[0]);

	sortt(arr, n, uzlazno);
	for (std::size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';


	sortt(arr, n, silazno);
	for (std::size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';


	sortt(arrDouble, nd, uzlazno);
	for (std::size_t i = 0; i < nd; i++)
		std::cout << arrDouble[i] << ' ';
	std::cout << '\n';


	sortt(arrDouble, nd, silazno);
	for (std::size_t i = 0; i < nd; i++)
		std::cout << arrDouble[i] << ' ';
	std::cout << '\n';

	return 0;
}