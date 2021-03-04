#include <iostream>
#include <algorithm>

using namespace std;

string convertToTitle(int n);

int main(int argc, char const *argv[])
{
    cout << convertToTitle(701) << endl;
    return 0;
}

string convertToTitle(int n)
{
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", res;

    while (n)
    {
        n--;
        int rem = n % 26;
        res += letters[rem];
        n /= 26;
    }

    reverse(res.begin(), res.end());
    return res;
}