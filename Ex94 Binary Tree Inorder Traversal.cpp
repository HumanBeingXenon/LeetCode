#include <iostream>
#include <vector>
#include <stack>
#include "data_structure.hpp"

using namespace std;

void print_vector(vector<int> v);
vector<int> inorderTraversalByIteration(TreeNode *root);
vector<int> inorderTraversalByRecursion(TreeNode *root);
vector<int> inorderTraversalByMorris(TreeNode *root);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, null, 5, 6, null, 7, null, null, 8, 9, null, null, null, 10, null, 11, null, null, 12};
    TreeNode *root = init_tree(arr, sizeof(arr) / sizeof(int));
    print_tree(root);
    vector<int> v1 = inorderTraversalByIteration(root);
    print_vector(v1);
    vector<int> v2 = inorderTraversalByRecursion(root);
    print_vector(v2);
    vector<int> v3 = inorderTraversalByMorris(root);
    print_vector(v3);
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

vector<int> inorderTraversalByIteration(TreeNode *root)
{
    vector<int> vector_result;
    if (root == nullptr)
        return vector_result;

    stack<TreeNode *> stack_treenode;
    TreeNode *cur = root;
    while (cur != nullptr || !stack_treenode.empty())
    {
        while (cur != nullptr)
        {
            stack_treenode.push(cur);
            cur = cur->left;
        }
        cur = stack_treenode.top();
        stack_treenode.pop();
        vector_result.push_back(cur->val);
        cur = cur->right;
    }
    return vector_result;
}

void inorderhelper(TreeNode *root, vector<int> &v)
{
    if (root != nullptr)
    {
        if (root->left != nullptr)
            inorderhelper(root->left, v);
        v.push_back(root->val);
        if (root->right != nullptr)
            inorderhelper(root->right, v);
    }
}

vector<int> inorderTraversalByRecursion(TreeNode *root)
{
    vector<int> v;
    inorderhelper(root, v);
    return v;
}

vector<int> inorderTraversalByMorris(TreeNode *root)
{
    vector<int> vector_result;
    if (root == nullptr)
        return vector_result;

    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            vector_result.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right != nullptr && prev->right != cur)
                prev = prev->right;
            if (prev->right == nullptr)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                vector_result.push_back(cur->val);
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return vector_result;
}