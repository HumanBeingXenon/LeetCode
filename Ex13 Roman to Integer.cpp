#include <iostream>
#include <map>

using namespace std;

int romanToInt(string);
int romanToInt2(string);

int main()
{
	cout << romanToInt2("MCMXCIV") << endl;
	return 0;
}

int romanToInt(string s)
{
	map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	int result = 0, prev = 0, cur = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		cur = m[s[i]];
		if (cur >= prev)
			result += cur;
		else
			result -= cur;
		prev = cur;
	}
	return result;
}

int letter_to_value(char c)
{
	switch (c)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return 0;
	}
	return 0;
}

int romanToInt2(string s)
{
	int result = 0, prev = 0, cur = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		cur = letter_to_value(s[i]);
		if (cur >= prev)
			result += cur;
		else
			result -= cur;
		prev = cur;
	}
	return result;
}
