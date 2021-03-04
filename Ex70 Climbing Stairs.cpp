#include <iostream>

using namespace std;

int climbStairs(int n);

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}

int climbStairs(int n)
{
    int arr[n + 1];
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    return arr[n];
}
