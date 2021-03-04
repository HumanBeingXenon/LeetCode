#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "data_structure.hpp"

using namespace std;

void print_vector(vector<int> v);
vector<int> preorderTraversal(TreeNode *root);
vector<int> preorderTraversalByIteration(TreeNode *root);
vector<int> preorderTraversalByRecursion(TreeNode *root);
vector<int> preorderTraversalByMorris(TreeNode *root);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, null, 5, 6, null, 7, null, null, 8, 9, null, null, null, 10, null, 11, null, null, 12};
    TreeNode *root = init_tree(arr, sizeof(arr) / sizeof(int));
    print_tree(root);
    vector<int> v1 = preorderTraversalByRecursion(root);
    print_vector(v1);
    vector<int> v2 = preorderTraversalByIteration(root);
    print_vector(v2);
    vector<int> v3 = preorderTraversalByMorris(root);
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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> vector_result;
    if (root == nullptr)
        return vector_result;

    stack<TreeNode *> stack_treenode;
    stack_treenode.push(root);
    while (!stack_treenode.empty())
    {
        TreeNode *ptr = stack_treenode.top();
        stack_treenode.pop();
        vector_result.push_back(ptr->val);
        if (ptr->right != nullptr)
            stack_treenode.push(ptr->right);
        if (ptr->left != nullptr)
            stack_treenode.push(ptr->left);
    }
    return vector_result;
}

vector<int> preorderTraversalByIteration(TreeNode *root)
{
    vector<int> vector_result;
    if (root == nullptr)
        return vector_result;

    stack<TreeNode *> stack;
    stack.push(root);
    TreeNode *cur = root->left;
    vector_result.push_back(root->val);
    while (!stack.empty() || cur != nullptr)
    {
        while (cur != nullptr)
        {
            stack.push(cur);
            vector_result.push_back(cur->val);
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        cur = cur->right;
    }
    return vector_result;
}

void preorderhelper(TreeNode *root, vector<int> &v)
{
    if (root != nullptr)
    {
        v.push_back(root->val);
        if (root->left != nullptr)
            preorderhelper(root->left, v);
        if (root->right != nullptr)
            preorderhelper(root->right, v);
    }
}

vector<int> preorderTraversalByRecursion(TreeNode *root)
{
    vector<int> v;
    preorderhelper(root, v);
    return v;
}

vector<int> preorderTraversalByMorris(TreeNode *root)
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
                vector_result.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return vector_result;
}