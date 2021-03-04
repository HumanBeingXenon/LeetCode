#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n);

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> vi = grayCode(n);
    for (int i = 0; i < vi.size(); i++)
        cout << hex << vi[i] << " ";
    cout << endl;
    return 0;
}

vector<int> grayCode(int n)
{
    if (n == 0)
    {
        return vector<int>({0});
    }
    else
    {
        int size = 1 << n;
        vector<int> vi(size);
        vi[0] = 0;
        for (int i = 1; i < size; i++)
        {
            int t = i;
            for (int j = 0; t > 0; j++)
            {
                int Bi = t & 1;
                int Bi1 = (t >> 1) & 1;
                vi[i] += (Bi ^ Bi1) << j;
                t >>= 1;
            }
        }
        return vi;
    }
}