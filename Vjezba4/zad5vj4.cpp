#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void reverse_strings(std::vector<std::string>& s)
{
	for (std::string& x : s)
		std::reverse(x.begin(), x.end());
}

void print_vector(std::vector<std::string>& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		std::cout << s[i] << ' ';
	}
}

int main()
{
	std::vector<std::string> s{"hello","world","c++"};

	std::cout << "String: ";
	print_vector(s);
	std::cout << '\n';

	reverse_strings(s);

	std::cout << "Okrenuti: ";
	print_vector(s);

	return 0;
}