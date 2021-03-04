#include <iostream>
#include <queue>
#include "data_structure.hpp"

bool isSymmetric(TreeNode *root);

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 2, 2, 3, 4, 4, 3}, v2 = {9, -42, -42, null, 76, 76, null, null, 13, null, 13};
    TreeNode *root1 = init_tree(v1), *root2 = init_tree(v2);
    print_tree(root1);
    print_tree(root2);
    cout << (isSymmetric(root1) ? "true" : "false") << endl;
    cout << (isSymmetric(root2) ? "true" : "false") << endl;
    destroy_tree(root1);
    destroy_tree(root2);
    return 0;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;

    queue<TreeNode *> queue;
    queue.push(root);
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode *ptr1 = queue.front();
        queue.pop();
        TreeNode *ptr2 = queue.front();
        queue.pop();
        if (ptr1 == nullptr && ptr2 == nullptr)
            continue;
        if (ptr1 == nullptr || ptr2 == nullptr)
            return false;
        if (ptr1->val != ptr2->val)
            return false;
        queue.push(ptr1->left);
        queue.push(ptr2->right);
        queue.push(ptr1->right);
        queue.push(ptr2->left);
    }
    return true;
}