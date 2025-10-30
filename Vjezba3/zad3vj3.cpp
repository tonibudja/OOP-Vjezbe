#include <iostream>
#include <vector>
#include <cstddef>

int main()
{
	std::vector<int> niz = {1,2,3,4,5,6,7,8};

	auto jeParan = [](int x) {return x % 2 == 0; };
	auto jeNeparan = [](int x) {return x % 2 != 0; };

	auto udvostruci = [](int x) {return x * 2;  };
	auto prepolovi = [](int x) {return x / 2;  };

	int sum = 0;
	int prod = 1;
	int prag = 2;

	auto dodajSumu = [&sum](int x) {sum += x; };
	auto dodajProdukt = [&prod](int x) {prod *= x; };
	auto dodajSumPrag = [prag, &sum](int x) {if (x > prag)sum += x; };

	for (int& x : niz)
	{
		if (jeParan(x))
			x = prepolovi(x);
		else
			x = udvostruci(x);
	}
	for (int i : niz)
		std::cout << i << ' ';

	for (int x : niz)
	{
		dodajSumu(x);
		dodajProdukt(x);
	}

	std::cout << "Suma: " << sum << "\n";
	std::cout << "Produkt: " << prod << "\n";

	for (int x : niz)
	{
		dodajSumPrag(x);
	}

	std::cout << "Suma brojeva > " << prag << " : " << sum << "\n";

	return 0;
}