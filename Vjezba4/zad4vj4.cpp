#include <iostream>
#include <string>

bool je_samoglasnik(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}



std::string word_to_pig_latin(std::string& s)
{
	if (je_samoglasnik(s[0]))
		return s + "hey";
	else
		return s.substr(1) + s[0] + "ay";
}

int main()
{
	std::string s1{"apple"};
	std::string s2{"hello"};

	
	
	std::cout << word_to_pig_latin(s1) << '\n';
	std::cout << word_to_pig_latin(s2) << '\n';

	return 0;
}