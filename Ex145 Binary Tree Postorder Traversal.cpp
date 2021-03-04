#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include "data_structure.hpp"

using namespace std;

void print_vector(vector<int> v);
vector<int> postorderTraversalByIteration(TreeNode *root);
vector<int> postorderTraversalByIteration2(TreeNode *root);
vector<int> postorderTraversalByRecursion(TreeNode *root);
vector<int> postorderTraversalByMorris(TreeNode *root);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, null, 5, 6, null, 7, null, null, 8, 9, null, null, null, 10, null, 11, null, null, 12};
    TreeNode *root = init_tree(arr, sizeof(arr) / sizeof(int));
    print_tree(root);
    vector<int> v1 = postorderTraversalByIteration2(root);
    print_vector(v1);
    vector<int> v2 = postorderTraversalByRecursion(root);
    print_vector(v2);
    vector<int> v3 = postorderTraversalByMorris(root);
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

vector<int> postorderTraversalByIteration(TreeNode *root)
{
    vector<int> vector_postorder;
    if (root == nullptr)
        return vector_postorder;

    stack<TreeNode *> stack_treenode;
    stack_treenode.push(root);
    while (!stack_treenode.empty())
    {
        TreeNode *ptr = stack_treenode.top();
        stack_treenode.pop();
        if (ptr->left != nullptr)
            stack_treenode.push(ptr->left);
        if (ptr->right != nullptr)
            stack_treenode.push(ptr->right);
        vector_postorder.push_back(ptr->val);
    }
    reverse(vector_postorder.begin(), vector_postorder.end());
    return vector_postorder;
}

vector<int> postorderTraversalByIteration2(TreeNode *root)
{
    vector<int> vector_result;
    if (root == nullptr)
        return vector_result;

    stack<TreeNode *> stack_treenode;
    stack_treenode.push(root);
    TreeNode *cur = root->right;
    vector_result.push_back(root->val);
    while (!stack_treenode.empty() || cur != nullptr)
    {
        while (cur != nullptr)
        {
            stack_treenode.push(cur);
            vector_result.push_back(cur->val);
            cur = cur->right;
        }
        cur = stack_treenode.top();
        stack_treenode.pop();
        cur = cur->left;
    }
    reverse(vector_result.begin(), vector_result.end());
    return vector_result;
}

void postorderhelper(TreeNode *root, vector<int> &v)
{
    if (root != nullptr)
    {
        if (root->left != nullptr)
            postorderhelper(root->left, v);
        if (root->right != nullptr)
            postorderhelper(root->right, v);
        v.push_back(root->val);
    }
}

vector<int> postorderTraversalByRecursion(TreeNode *root)
{
    vector<int> v;
    postorderhelper(root, v);
    return v;
}

vector<int> postorderTraversalByMorris(TreeNode *root)
{
    vector<int> vector_result;
    if (root == nullptr)
        return vector_result;

    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (cur->right == nullptr)
        {
            vector_result.push_back(cur->val);
            cur = cur->left;
        }
        else
        {
            TreeNode *prev = cur->right;
            while (prev->left != nullptr && prev->left != cur)
                prev = prev->left;
            if (prev->left == nullptr)
            {
                prev->left = cur;
                vector_result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                prev->left = nullptr;
                cur = cur->left;
            }
        }
    }
    reverse(vector_result.begin(), vector_result.end());
    return vector_result;
}