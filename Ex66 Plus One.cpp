#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits);
void print_vector(vector<int> v);

int main(int argc, char const *argv[])
{
    vector<int> digits = {9, 9, 9, 9};
    vector<int> digits2 = plusOne(digits);
    print_vector(digits2);
    return 0;
}

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

vector<int> plusOne(vector<int> &digits)
{
    int size = digits.size();
    digits[size - 1]++;
    int carrier = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        digits[i] += carrier;
        carrier = digits[i] / 10;
        digits[i] %= 10;
    }
    if (carrier)
    {
        digits.insert(digits.begin(), carrier);
    }
    return digits;
}