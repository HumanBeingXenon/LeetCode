#include <iostream>
#include <vector>
#include <stack>
#include "data_structure.hpp"

using namespace std;

void recoverTree(TreeNode *root);
void recoverTree2(TreeNode *root);
void recoverTree3(TreeNode *root);

vector<TreeNode *> vector_treenode;

int main(int argc, char const *argv[])
{
    vector<int> v = {3, 1, 4, null, null, 2};
    vector<int> v2 = {10, 7, 13, 20, 9, 11, 17, null, null, null, null, null, 12, null, 4};
    TreeNode *root = init_tree(v);
    TreeNode *root2 = init_tree2(v2);
    print_tree(root2);
    recoverTree3(root2);
    print_tree(root2);
    return 0;
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    vector_treenode.push_back(root);
    inorder(root->right);
}

void recoverTree(TreeNode *root)
{
    inorder(root);
    int cnt = 0, first = 0, second = 0;
    for (int i = 1; i < vector_treenode.size(); i++)
    {
        if (vector_treenode[i]->val < vector_treenode[i - 1]->val)
            if (!cnt)
            {
                first = i - 1;
                second = i;
                cnt++;
            }
            else
            {
                second = i;
                cnt++;
            }
    }
    int temp = vector_treenode[first]->val;
    vector_treenode[first]->val = vector_treenode[second]->val;
    vector_treenode[second]->val = temp;
}

void recoverTree2(TreeNode *root)
{
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
        vector_treenode.push_back(cur);
        cur = cur->right;
    }

    int cnt = 0, first, second;
    for (int i = 1; i < vector_treenode.size(); i++)
    {
        if (vector_treenode[i]->val < vector_treenode[i - 1]->val)
            if (!cnt)
            {
                first = i - 1;
                second = i;
                cnt++;
            }
            else
            {
                second = i;
                cnt++;
            }
    }
    int temp = vector_treenode[first]->val;
    vector_treenode[first]->val = vector_treenode[second]->val;
    vector_treenode[second]->val = temp;
}

void recoverTree3(TreeNode *root)
{
    TreeNode *cur = root, *prev = nullptr;                         //Pointers for Morris Traversal
    TreeNode *first = nullptr, *second = nullptr, *pred = nullptr; //Pointers for storing exchanged nodes, *pred points at predecessor in inorder traversal
    while (cur != nullptr)
    {
        if (cur->left == nullptr)
        {
            //---------------------
            if (pred != nullptr && cur->val < pred->val)
            {
                second = cur;
                if (first == nullptr)
                    first = pred;
            }
            pred = cur;
            //---------------------
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
                //---------------------
                if (pred != nullptr && cur->val < pred->val)
                {
                    second = cur;
                    if (first == nullptr)
                        first = pred;
                }
                pred = cur;
                //---------------------
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    swap(first->val, second->val);
}