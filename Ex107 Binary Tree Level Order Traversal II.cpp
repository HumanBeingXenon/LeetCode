#include <algorithm>
#include <iostream>
#include <queue>
#include "data_structure.hpp"

using namespace std;

vector<vector<int>> levelOrderBottom(TreeNode *root);

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, null, 5, 6, null, 7, null, null, 8, 9, null, null, null, 10, null, 11, null, null, 12};
    TreeNode *root = init_tree(v);
    print_tree(root);
    vector<vector<int>> level_order = levelOrderBottom(root);
    destroy_tree(root);
    return 0;
}

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> vector_level_order;
    if (root == nullptr)
        return vector_level_order;

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int level_size = queue.size();
        vector<int> vector_cur;
        for (int i = 0; i < level_size; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();
            vector_cur.emplace_back(node->val);
            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
        vector_level_order.emplace_back(vector_cur);
    }
    reverse(vector_level_order.begin(), vector_level_order.end());
    return vector_level_order;
}