#include <iostream>

using namespace std;

bool isPalindrome(string s);

int main(int argc, char const *argv[])
{
    //string s = "A man, a plan, a canal: Panama";
    string s = "race a car";
    cout << isPalindrome(s) << endl;
    return 0;
}

bool isPalindrome(string s)
{
    string s1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
            s1 += s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s1 += (s[i] + 'a' - 'A');
        }
    }
    //cout << s1 << endl;
    int len = s1.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s1[i] != s1[len - i - 1])
            return false;
    }
    return true;
}