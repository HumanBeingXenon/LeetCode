#include <iostream>

using namespace std;

int divide(long dividend, long divisor);

int main(int argc, char const *argv[])
{
    cout << divide(INT_MIN, 2) << endl;
    return 0;
}

int divide(long dividend, long divisor)
{
    if (divisor == 0)
        return INT_MAX;
    if (dividend == INT_MIN)
        if (divisor == -1)
            return INT_MAX;
        else if (divisor == 1)
            return INT_MIN;
    int sign = dividend ^ divisor;
    long long divid = dividend, divis = divisor;
    if (divid < 0)
        divid = -divid;
    if (divis < 0)
        divis = -divis;
    int res = 0;
    while (divid >= divis)
    {
        int lshift_cnt = 0;
        while (divid >= divis << lshift_cnt)
            lshift_cnt++;
        res += 1 << (lshift_cnt - 1);
        divid -= (divis << (lshift_cnt - 1));
    }
    if (sign < 0)
        res = -res;
    return res;
}
