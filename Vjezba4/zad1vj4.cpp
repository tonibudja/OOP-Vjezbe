#include <iostream>
#include <vector>

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
	std::cout << "Vektor: ";
	for (int x : v)
		std::cout << x << ' ';


}

int main()
{
	std::vector<int>v;

	input_vector(v);
	print_vector(v);

	return 0;
}