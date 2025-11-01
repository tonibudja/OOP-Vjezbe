#include <iostream>
#include <string>

void fix_spaces(std::string& s)
{
	for (size_t i = 0;i + 1< s.size();)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
			s.erase(i, 1);
		else
			i++;
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		if ((s[i] == ',' || s[i] == '.') && s[i - 1] == ' ' && i > 0)
		{
			s.erase(i - 1,1);
			i--;
		}
	}

	for (size_t i = 0; i + 1 < s.size(); i++)
	{
		if (s[i] == ',' && s[i + 1] != ' ')
		{
			s.insert(i + 1, " ");
			i++;
		}
	}
}

int main()
{
	std::string s{ "Puno    razmaka   ,i tocka  .            " };
	fix_spaces(s);

	std::cout << s << '\n';

	return 0;
}