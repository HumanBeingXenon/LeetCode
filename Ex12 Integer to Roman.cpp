#include <iostream>

using namespace std;

string intToRoman(int num);
string intToRoman2(int num);

/*
    I-1 V-5 X-10 L-50 C-100 D-500 M-1000
*/

int main(int argc, char const *argv[])
{
    cout << intToRoman2(1996) << endl;
    return 0;
}

int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

string intToRoman(int num)
{
    string res = "";
    int cnt = num / 1000;
    num %= 1000;
    if (cnt)
        res += string(cnt, 'M');
    if (num / 900)
    {
        res += "CM";
        num %= 900;
    }
    if (num / 500)
    {
        res += "D";
        num %= 500;
    }
    if (num / 400)
    {
        res += "CD";
        num %= 400;
    }
    cnt = num / 100;
    if (cnt)
        res += string(cnt, 'C');
    num %= 100;
    if (num / 90)
    {
        res += "XC";
        num %= 90;
    }
    if (num / 50)
    {
        res += "L";
        num %= 50;
    }
    if (num / 40)
    {
        res += "XL";
        num %= 40;
    }
    cnt = num / 10;
    num %= 10;
    if (cnt)
        res += string(cnt, 'X');
    if (num / 9)
    {
        res += "IX";
        num %= 9;
    }
    if (num / 5)
    {
        res += "V";
        num %= 5;
    }
    if (num / 4)
    {
        res += "IV";
        num %= 4;
    }
    if (num)
        res += string(num, 'I');
    return res;
}

string intToRoman2(int num)
{
    string res;
    for (int i = 0; i < 13; i++)
    {
        while (num >= value[i])
        {
            num -= value[i];
            res += roman[i];
        }
    }
    return res;
}