#include <iostream>
#include <vector>
#include <unordered_map>
#include "data_structure.hpp"

using namespace std;

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);

unordered_map<int, int> map; //A map that stores the indices of each number in inorder vector

int main(int argc, char const *argv[])
{
    //vector<int> inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 10, 6, 9, 12, 11}, postorder = {7, 4, 2, 5, 10, 8, 12, 11, 9, 6, 3, 1};
    TreeNode *root = buildTree(inorder, postorder);
    print_tree(root);
    return 0;
}

TreeNode *build_helper(vector<int> &postorder, int postleft, int postright, int inleft, int inright)
{
    if (postleft > postright || inleft > inright)
        return nullptr;
    int rootval = postorder[postright];
    TreeNode *root = new TreeNode(rootval);
    int idx = map[rootval];
    root->left = build_helper(postorder, postleft, postright - inright + idx - 1, inleft, idx - 1);
    root->right = build_helper(postorder, postright - inright + idx, postright - 1, idx + 1, inright);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int size = inorder.size();

    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i;

    return build_helper(postorder, 0, size - 1, 0, size - 1);
}