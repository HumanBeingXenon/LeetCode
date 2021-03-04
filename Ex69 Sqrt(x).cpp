#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x);
int mySqrt2(int x);

int main(int argc, char const *argv[])
{
    cout << mySqrt(65536) << endl;
    return 0;
}

//Find floor(sqrt(x)) by binary search
int mySqrt(int x)
{
    if (x == 0)
        return 0;

    int low = 0, high = x;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((long long)mid * mid <= x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

//Find floor(sqrt(x)) by Newton's Iteration Method
int mySqrt2(int x)
{
    if (x == 0)
        return 0;

    double C = x, x0 = x;
    while (true)
    {
        double xi = 0.5 * (x0 + C / x0);
        if (fabs(x0 - xi) < 1e-7)
            break;
        x0 = xi;
    }
    return int(x0);
}