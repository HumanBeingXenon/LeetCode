#include <iostream>
#include <cmath>
#include "data_structure.hpp"

using namespace std;

bool isBalanced(TreeNode *root);
bool isBalanced2(TreeNode *root);

int main(int argc, char const *argv[])
{
    int arr1[] = {3, 9, 20, null, null, 15, 7};
    TreeNode *root1 = init_tree(arr1, sizeof(arr1) / sizeof(int));
    print_tree(root1);
    cout << (isBalanced(root1) ? "true" : "false") << endl;

    int arr2[] = {1, 2, 2, 3, 3, null, null, 4, 4};
    TreeNode *root2 = init_tree(arr2, sizeof(arr2) / sizeof(int));
    print_tree(root2);
    cout << (isBalanced(root2) ? "true" : "false") << endl;
    return 0;
}

int depth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    else
        return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    else
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int depth2(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lheight = depth2(root->left), rheight = depth2(root->right);
    if (lheight == -1 || rheight == -1 || abs(lheight - rheight) > 1)
        return -1;
    else
        return max(lheight, rheight) + 1;
}

bool isBalanced2(TreeNode *root)
{
    if (root == nullptr)
        return true;
    else
        return depth2(root) != -1;
}