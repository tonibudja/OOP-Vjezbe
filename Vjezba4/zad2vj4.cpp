#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void input_vector(std::vector<int>& v)
{
	while (1)
	{
		int broj;
		std::cout << "Unesi broj: ";
		std::cin >> broj;
		if (broj == 0) break;

		v.push_back(broj);
	}
}

void print_vector(const std::vector<int>& v)
{
	for (int x : v)
		std::cout << x << ' ';


}

int main()
{
	std::vector<int>v;

	input_vector(v);
	std::cout << "Orginalni vektor: ";
	print_vector(v);
	std::cout << '\n';

	std::vector<int>jedinstveni_v;
	for (int x : v)
		if (std::find(jedinstveni_v.begin(),jedinstveni_v.end(),x) == jedinstveni_v.end())
			jedinstveni_v.push_back(x);

	std::cout << "Jedinstveni vektor: ";
	print_vector(jedinstveni_v);
	std::cout << '\n';


	std::sort(jedinstveni_v.begin(), jedinstveni_v.end(), [](int a, int b) {return std::abs(a) < std::abs(b); });

	std::cout << "Jedinstveni po aps. vrijednosti: ";
	print_vector(jedinstveni_v);

	return 0;
}