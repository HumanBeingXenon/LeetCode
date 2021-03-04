#include <iostream>

using namespace std;

double myPow(double x, int n);

int main(int argc, char const *argv[])
{
    cout << myPow(1, -2147483648) << endl;
    return 0;
}

double myPow(double x, int n)
{
    if (x == 1 || n == 0)
        return 1;
    else if (x == -1)
        if (n % 2)
            return -1;
        else
            return 1;
    else if (x == 0)
        return 0;
    else if (n == 1)
        return x;

    long long N = n;
    if (N < 0)
        N = -N;
    double res = 1;
    while (N > 0)
    {
        if (N & 1)
            res *= x;
        N >>= 1;
        x *= x;
    }
    if (n >= 0)
        return res;
    else
        return 1 / res;
}
