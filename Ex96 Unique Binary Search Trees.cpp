#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n);

int main(int argc, char const *argv[])
{
    cout << numTrees(8) << endl;
    return 0;
}

// node_num = 0, BST_num[0] = 1
// node_num = 1, BST_num[1] = 1
// node_num = 2, BST_num[2] = 2
// node_num = 3, BST_num[3] = BST_num[0] * BST_num[2] + BST_num[1] * BST_num[1] + BST_num[2] * BST_num[0] = 5
// node_num = n, BST_num[n] = BST_num[0] * BST_num[n-1] + BST_num[2] * BST_num[n-2] + ... + BST_num[n-2] * BST_num[2] + BST_num[n-1] * BST_num[0]
int numTrees(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else if (n == 2)
        return 2;

    vector<int> num(n + 1);
    num[0] = num[1] = 1, num[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int left = j - 1, right = i - j;
            num[i] += num[left] * num[right];
        }
    }
    return num[n];
}
