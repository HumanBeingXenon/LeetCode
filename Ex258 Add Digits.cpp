#include <iostream>

using namespace std;

int addDigits(int num);

int main(int argc, char const *argv[])
{
    cout << addDigits(9999) << endl;
    return 0;
}

int addDigits(int num)
{
    while (num >= 10)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

//Reference: https://en.wikipedia.org/wiki/Digital_root
//digit root -> dr(n)
//dr(n) = 1 + ((n - 1) mod (b-1)), n != 0
//        0                      , n == 0
int addDigits(int num)
{
    return num ? 1 + --num % 9 : 0;
}