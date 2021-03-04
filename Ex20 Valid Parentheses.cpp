#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isValid(string);

int main()
{
	string s = "([)]", s2 = "([]{[]})";
	cout << (isValid(s) ? "true" : "false") << " " << (isValid(s2) ? "true" : "false") << endl;
	return 0;
}

bool isValid(string s)
{
	stack<char> stk;
	map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			stk.push(s[i]);
			continue;
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (!stk.empty())
			{
				if (m[s[i]] == stk.top())
					stk.pop();
				else
					return false;
			}
			else
			{
				return false;
			}
		}
	}
	if (stk.empty())
		return true;
	else
		return false;
}
