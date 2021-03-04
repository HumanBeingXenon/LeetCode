#include <iostream>

using namespace std;

string addBinary(string a, string b);

int main(int argc, char const *argv[])
{
    string a = "111111", b = "1", sum;
    sum = addBinary(a, b);
    cout << a << "+" << b << "=" << sum << endl;
    return 0;
}

/*
    a_i b_i c_{i-1} s_i c_i
     0   0    0      0   0
     0   0    1      1   0
     0   1    0      1   0 
     0   1    1      0   1
     1   0    0      1   0
     1   0    1      0   1
     1   1    0      0   1
     1   1    1      1   1
    s_i = a_i ^ b_i ^ c_{i-1}
    c_i = (a_i ^ b_i) & c_{i-1} + (a_i & b_i)
*/
string addBinary(string a, string b)
{
    int len_a = a.length(), len_b = b.length();
    if (len_a > len_b)
    {
        b = string(len_a - len_b, '0') + b;
        len_b = len_a;
    }
    else if (len_a < len_b)
    {
        a = string(len_b - len_a, '0') + a;
        len_a = len_b;
    }
    int carrier = 0, ai, bi;
    string res = string(len_a, '0');
    for (int i = len_a - 1; i >= 0; i--)
    {
        ai = a[i] - '0', bi = b[i] - '0';
        res[i] = (ai ^ bi ^ carrier) + '0';
        carrier = ((ai ^ bi) & carrier | (ai & bi));
    }
    if (carrier)
        res = "1" + res;
    return res;
}