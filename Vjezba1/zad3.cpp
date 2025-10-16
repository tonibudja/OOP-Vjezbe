#include <iostream>
#include <string>
#include <cctype>


int main()
{
	std::string s;
	std::cout << "Unesi string: ";
	std::getline(std::cin, s);

	for (char &c : s)
	{
		if (isalpha(c)) c = toupper(c);
		if (isdigit(c)) c = '*';
		if (c == ' ' || c == '\t') c = '_';
	}

	std::cout << s;

	return 0;
}