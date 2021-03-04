#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n);
bool isHappy2(int n);

int main(int argc, char const *argv[])
{
    cout << (isHappy2(15) ? "true" : "false") << endl;
    return 0;
}

bool isHappy(int n)
{
    unordered_set<int> set;
    int x = n;
    cout << n << endl;
    while (x != 1)
    {
        if (set.find(x) != set.end())
            return false;
        else
            set.emplace(x);
        int t1 = 0;
        while (x)
        {
            int t2 = x % 10;
            t1 += t2 * t2;
            x /= 10;
        }
        x = t1;
        cout << x << endl;
    }
    return true;
}

bool isHappy2(int n)
{
    unordered_set<int> set;
    cout << n << endl;
    while (set.find(n) == set.end())
    {

        set.emplace(n);
        int t1 = 0;
        while (n)
        {
            int t2 = n % 10;
            t1 += t2 * t2;
            n /= 10;
        }
        n = t1;
        cout << n << endl;
        if (n == 1)
            return true;
    }
    return false;
}