#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

vector<TreeNode *> generateTrees(int n);

int main(int argc, char const *argv[])
{
    //vector<int> v = {2, 1, 3, 0, 7, 9, 1, 2, null, 1, 0, null, null, 8, 8, null, null, null, null, 7};
    //TreeNode *root = init_tree(v);
    //print_tree(root);
    vector<TreeNode *> vector_BST = generateTrees(4);
    for (TreeNode *root : vector_BST)
        print_tree(root);
    return 0;
}

vector<TreeNode *> generate_helper(int begin, int end)
{
    if (begin > end)
        return {nullptr};
    vector<TreeNode *> all_trees;
    for (int i = begin; i <= end; i++)
    {
        vector<TreeNode *> left_trees = generate_helper(begin, i - 1);
        vector<TreeNode *> right_trees = generate_helper(i + 1, end);
        int left_size = left_trees.size(), right_size = right_trees.size();
        if (left_size == 0)
        {
            if (right_size == 0)
            {
                TreeNode *cur_tree = new TreeNode(i);
                all_trees.emplace_back(cur_tree);
            }
            else
            {
                for (TreeNode *right : right_trees)
                {
                    TreeNode *cur_tree = new TreeNode(i);
                    cur_tree->right = right;
                    all_trees.emplace_back(cur_tree);
                }
            }
        }
        else if (right_size == 0)
        {
            for (TreeNode *left : left_trees)
            {
                TreeNode *cur_tree = new TreeNode(i);
                cur_tree->left = left;
                all_trees.emplace_back(cur_tree);
            }
        }
        else
        {
            for (TreeNode *left : left_trees)
            {
                for (TreeNode *right : right_trees)
                {
                    TreeNode *cur_tree = new TreeNode(i);
                    cur_tree->left = left;
                    cur_tree->right = right;
                    all_trees.emplace_back(cur_tree);
                }
            }
        }
    }
    return all_trees;
}

vector<TreeNode *> generateTrees(int n)
{
    if (n == 0)
        return {};
    else
        return generate_helper(1, n);
}