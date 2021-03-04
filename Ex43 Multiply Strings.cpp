#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2);

int main(int argc, char const *argv[])
{
    string num1 = "235786", num2 = "3445";
    cout << multiply(num1, num2) << endl;
    return 0;
}

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    int m = num1.size(), n = num2.size();
    vector<int> resarr = vector<int>(m + n);

    for (int i = m - 1; i >= 0; i--)
    {
        int x = num1[i] - '0';
        for (int j = n - 1; j >= 0; j--)
        {
            int y = num2[j] - '0';
            resarr[i + j + 1] += x * y;
        }
    }

    for (int i = m + n - 1; i > 0; i--)
    {
        resarr[i - 1] += resarr[i] / 10;
        resarr[i] %= 10;
    }
    string resstr;
    for (int i = resarr[0] ? 0 : 1; i < resarr.size(); i++)
        resstr += resarr[i] + '0';
    return resstr;
}